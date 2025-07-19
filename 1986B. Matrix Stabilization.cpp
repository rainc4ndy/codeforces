#include <bits/stdc++.h>
using namespace std;

const int mod = 101;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int v[mod][mod];

P dir[4] = {
	{0, 1},
	{1, 0},
	{ -1, 0},
	{0, -1}
};

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	int x, y;
	int mx = 0;
	bool ok = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mx = 0;
			ok = true;
			for (int k = 0; k < 4; k++) {
				x = i, y = j;
				x += dir[k].x;
				y += dir[k].y;

				if (x < 0 || x >= n || y < 0 || y >= m)
					continue;

				if (v[x][y] >= v[i][j]) {
					ok = false;
					break;
				} else {
					mx = max(mx, v[x][y]);
				}
			}
			if (ok) {
				v[i][j] = mx;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << v[i][j];
			cout << ' ';
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}