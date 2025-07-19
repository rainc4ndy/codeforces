#include <bits/stdc++.h>
#include <locale>
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

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n+1, vector<int>());
	vector<int> w(n+1);
	vector<int> dp(n+1);
	vector<bool> bad(n+1);
	vector<bool> vis(n+1);
	int root = 0;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		if (!x) {
			root = i;
		} else {
			graph[x].eb(i);
			graph[i].eb(x);
		}
		w[i] = y;
	}

	auto dfs = [&](auto && self, int u) -> int {
		int sum = w[u];
		for (int i = 0; i < graph[u].size(); i++) {
			auto ch = graph[u][i];
			if (vis[ch] || bad[ch]) continue;

			vis[graph[u][i]] = true;
			sum += self(self, graph[u][i]);
			vis[graph[u][i]] = false; // 恢复
		}
		dp[u] = sum;
		return sum;
	};

	vis[1] = true;
	int want = dfs(dfs, 1) / 3;
	vis[1] = false;

	auto dfs2 = [&](auto && self, int u) -> int {
		if (dp[u] == want) {
			bad[u] = true;
			return u;
		}
		for (int i = 0; i < graph[u].size(); i++) {
			auto ch = graph[u][i];
			if (vis[ch] || bad[ch]) continue;
			vis[ch] = true;
			auto ok = self(self, ch);
			vis[ch] = false;
			if (ok != -1) {
				bad[u] = true;
				return ok;
			}
		}
		return -1;
	};

	for (int i = 1; i <=n;i++ ) cout << dp[i] << ' ';
	cout << endl;

	vis[1] = true;
	auto a = dfs2(dfs2, 1);
	vis[1] = false;

	for (int i = 1; i <=n;i++ ) dp[i] = 0;
	dfs(dfs, a);
	for (int i = 1; i <=n;i++ ) cout << dp[i] << ' ';
	cout << endl;


	auto b = dfs2(dfs2, root);

	if (a == -1 || b == -1) {
		cout << -1;
	} else {
		cout << a << ' ' << b;
	}
}

int main() {
	fastio;
	int _ = 1;
	while (_--) solve();

	return 0;
}