#include <bits/stdc++.h>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

int dp[100][100];
void solve() {
	int n;
	string s;
	cin >> s >> n;

	int m = s.size();
	dp[0][0] = 1;
	int tmp;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i - 1] == 'X' && i == 1) {
				for (int k = 1; k <= 9; k++) {
					tmp = (j * 10 + k) % n;
					dp[i][tmp] += dp[i - 1][j];
				}
			}
			else if (s[i - 1] == 'X' && i != 1) {
				for (int k = 0; k <= 9; k++) {
					tmp = (j * 10 + k) % n;
					dp[i][tmp] += dp[i - 1][j];
				}
			}
			else {
				tmp = (j * 10 + (s[i - 1] - '0')) % n;
				dp[i][tmp] += dp[i - 1][j];
			}
		}
	}
	cout << dp[m][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _ = 1;
	while (_--) solve();

	return 0;
}