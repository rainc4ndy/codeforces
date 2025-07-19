#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof (arr))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define random rnd(chrono::system_clock::now().time_since_epoch().count())
#define setdb(v) setprecision(v)
#define all(x) x.begin(), x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define sort_all(x) sort(all(x))
#define reverse_all(x) reverse(all(x))
#define x first
#define y second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
#define pb push_back
#define eb emplace_back
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const ll mod = 998244353;
#define RED cout << "\033[91m"
#define GREEN cout << "\033[92m"
#define YELLOW cout << "\033[93m"
#define BLUE cout << "\033[94m"
#define MAGENTA cout << "\033[95m"
#define CYAN cout << "\033[96m"
#define RESET cout << "\033[0m"
#define debug(x) cout << #x << ' ' << x << endl;
#define debug1(x)                     \
    RED;                              \
    cout << #x << ' ' << x << endl; \
    RESET;
#define debug2(x)                     \
    GREEN;                            \
    cout << #x << ' ' << x << endl; \
    RESET;
#define debug3(x)                     \
    BLUE;                             \
    cout << #x << ' ' << x << endl; \
    RESET;

/*
5 4
1 2
1 3
4 2
5 2
*/
void solve() {
	int n;
	cin >> n;
	vector<vector<pii>> graph(n, vector<pii>());
	vector<int> dp(n);
	vector<bool> vis(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		graph[x].eb(y, 1), graph[y].eb(x, 0);
	}

	auto dfs = [&](auto && self, int u) -> int {
		int tot = 0;
		for (int i = 0; i < graph[u].size(); i++) {
			if (vis[graph[u][i].x]) continue;
			vis[graph[u][i].x] = true;
			tot += self(self, graph[u][i].x) + (graph[u][i].y?0:1);
			vis[graph[u][i].x] = false;
		}
		return tot;
	};
	auto dfs2 = [&](auto && self, int u) -> void{
		for (int i = 0; i < graph[u].size(); i++) {
			if (vis[graph[u][i].x]) continue;
			vis[graph[u][i].x] = true;
			// cout << "u = " << u+1 << endl;
			// cout << "graph[u][i].x = " << graph[u][i].x+1 << endl;
			// cout << "graph[u][i].y = " << graph[u][i].y << endl;
			// cout << "dp[graph[u][i].x] = " << dp[graph[u][i].x] << endl;
			// cout << "dp[u] = " << dp[u] << endl;
			if (graph[u][i].y) {
				dp[graph[u][i].x] = dp[u] + 1;
			} else {
				dp[graph[u][i].x] = dp[u] - 1;
			}
			self(self, graph[u][i].x);
			vis[graph[u][i].x] = false;
		}
	};
	vis[0] = true;
	dp[0] = dfs(dfs, 0);
	vis[0] = false;

	vis[0] = true;
	dfs2(dfs2, 0);
	vis[0] = false;

	int mi = *min_element(all(dp));
	cout << mi << endl;
	for (int i = 0; i < n; i++) {
		if (dp[i] == mi) cout << i + 1 << ' ';
	}

}

int main() {
	fastio;
	int _ = 1;
	//cin >> _;
	while (_--) solve();

	return 0;
}