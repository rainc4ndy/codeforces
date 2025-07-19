#include <bits/stdc++.h>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

char v[4][mod];
bool bad[4][mod] {};

int n;
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[1][i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> v[2][i];
	}
	v[0][n + 1] = 'x';
	v[1][n + 1] = 'x';
	v[2][n + 1] = 'x';
	v[3][n + 1] = 'x';

	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i][j] == '.') {
				if (v[i - 1][j] == '.' ||
				        v[i + 1][j] == '.' ||
				        v[i][j - 1] == '.' ||
				        v[i][j + 1] == '.'
				   ) {

				} else {
					cout << 0 << endl;
					return;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i][j] == '.') {
				if (v[i-1][j] == '.' && 
					v[i][j-1] == 'x' &&
					v[i][j+1] == 'x' &&
					v[i-1][j+1] == '.' &&
					v[i-1][j-1] == '.') {
					ans++;
				}

				if (v[i+1][j] == '.' && 
					v[i][j-1] == 'x' &&
					v[i][j+1] == 'x' &&
					v[i+1][j+1] == '.' &&
					v[i+1][j-1] == '.') {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
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