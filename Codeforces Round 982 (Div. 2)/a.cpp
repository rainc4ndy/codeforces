#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n;
	cin >> n;
	vector<P> v(n);

	int ans = 0;

	vector<vector<bool>> g(200, vector<bool>(200));
	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y;
	}

	P mi {0x3f3f3f3f, 0x3f3f3f3f}, mx {0, 0};
	for (int i = 0; i < n; i++) {
		mi.x = min(mi.x, v[i].x);
		mi.y = min(mi.y, v[i].y);

		mx.x = max(mx.x, v[i].x);
		mx.y = max(mx.y, v[i].y);
	}

	cout << (mx.x) * 2 + (mx.y) * 2 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}