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

vector<int> g[100001];

void solve() {
	int n, m;
	cin >> n >> m;
	vector<bool> vis(n + 1, false);
	vector<int> col(n + 1, -1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g[x].eb(y), g[y].eb(x);
	}
	auto dfs = [&](auto && self, int pa, int cc) -> bool {
		col[pa] = cc;
		for (int i = 0; i < g[pa].size(); i++) {
			if (vis[g[pa][i]]) continue;
			if (col[pa] == col[g[pa][i]] && col[g[pa][i]] != -1) {
				return false;
			}
			if (col[g[pa][i]] != -1) continue;

			vis[g[pa][i]] = true;
			if (!self(self, g[pa][i], cc ^ 1)) {
				vis[g[pa][i]] = false;
				return false;
			}
			vis[g[pa][i]] = false;
		}
		return true;
	};
	for(int i = 1; i <= n; i++) {
		if (col[i] != -1) continue;
		if (!dfs(dfs, i, false)) {
			cout << -1;
			return; 
		}
	}
	
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		if (col[i] == 1) a++;
		else if (col[i] == 0) b++;
	}

	cout << a << endl;
	for (int i = 1; i <= n; i++)
		if (col[i] == 1) 
			cout << i << ' ';
	cout << endl;

	cout << b << endl;
	for (int i = 1; i <= n; i++)
		if (col[i] == 0) 
			cout << i << ' ';
}


int main() {
	fastio;
	int _ = 1;
	while (_--) solve();

	return 0;
}