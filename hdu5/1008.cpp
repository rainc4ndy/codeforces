#include <bits/stdc++.h>
using namespace std;

#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof (arr))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define random rnd(chrono::system_clock::now().time_since_epoch().count())
#define setdb(v) setprecision(v)
#define debug(x) cout << #x << ' ' << x << endl;
#define x first
#define y second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const ll mod = 998244353;

void solve() {
	int n, k;
	cin >> n >> k;


	vector<vector<int>> a(n, vector<int>(k));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> a[i][j];
		}
	}


	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	for (int j = 1; j <= k; ++j) {
		for (int i = 1; i <= n; ++i) {
			for (int x = 0; x < i; ++x) {
				int sum = 0;
				for (int idx = x; idx < i; ++idx) {
					sum += a[idx][j - 1];
				}
				dp[i][j] = max(dp[i][j], dp[x][j - 1] + sum);
			}
		}
	}

	
	cout << dp[n][k] << endl;
}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}