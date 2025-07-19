#include <bits/stdc++.h>
using namespace std;

#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof(arr))
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
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int maxn = 2e5 + 10;

vector<pll> g[maxn];
bool vis[maxn], inpath[maxn];

void solve() {
	int n;
	cin >> n;

	// 清空上一次使用的数据
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
		vis[i] = inpath[i] = false;
	}

	unordered_map<pll, ll, hash<pll>> dd;
	vector<ll> path;
	ll ans = 0;

	for (int i = 0; i < n - 1; ++i) {
		ll u, v, p, q;
		cin >> u >> v >> p >> q;
		g[u].eb(v, p);
		g[v].eb(u, q);
		dd[{u, v}] = p;
		dd[{v, u}] = q;
	}

	ll s, t;
	cin >> s >> t;

	// DFS找路径
	auto dfs = [&](auto &&self, ll u, ll fa) -> bool {
		if (u == t) {
			path.eb(u);
			return true;
		}
		vis[u] = true;
		for (auto &[v, val] : g[u]) {
			if (v == fa || vis[v]) continue;
			if (self(self, v, u)) {
				path.eb(u);
				ans += val;
				return true;
			}
		}
		return false;
	};

	dfs(dfs, s, -1);
	reverse_all(path);
	for (auto u : path) inpath[u] = true;
	fill(vis, vis + n + 1, false);

	// 统计支路贡献
	auto calc = [&](auto &&self, ll u, ll from) -> ll {
		vis[u] = true;
		ll res = 0;
		for (auto &[v, _] : g[u]) {
			if (vis[v] || inpath[v]) continue;
			ll gain = dd[{v, u}] + dd[{u, v}];
			res += max(0LL, self(self, v, u) + gain);
		}
		return res;
	};

	for (auto u : path) {
		ans += calc(calc, u, -1);
	}

	cout << ans << '\n';
}

int main() {
	fastio;
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
