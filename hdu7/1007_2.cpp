#include <bits/stdc++.h>
using namespace std;
#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof(arr))
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0)
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
#define debug1(x)                                                              \
  RED;                                                                         \
  cout << #x << ' ' << x << endl;                                              \
  RESET;
#define debug2(x)                                                              \
  GREEN;                                                                       \
  cout << #x << ' ' << x << endl;                                              \
  RESET;
#define debug3(x)                                                              \
  BLUE;                                                                        \
  cout << #x << ' ' << x << endl;                                              \
  RESET;

struct Edge {
    int to;
    ll p, q; // p = weight this->to, q = weight to->this
};

void solve() {
    int n;
    cin >> n;

    vector<vector<Edge>> g(n + 1);
    vector<int> pa(n + 1, -1);
    vector<ll> w_to_pa(n + 1, 0);
    vector<int> path;
    vector<bool> in_path(n + 1, false);
    vector<bool> visited(n + 1, false);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        ll p, q;
        cin >> u >> v >> p >> q;
        g[u].push_back({v, p, q});
        g[v].push_back({u, q, p});
    }
    int s, t;
    cin >> s >> t;

    function<bool(int, int)> dfs1 = [&](int u, int par) {
        if (u == t)
            return true;
        for (auto &e : g[u]) {
            if (e.to == par)
                continue;
            pa[e.to] = u;
            w_to_pa[e.to] = e.p;
            if (dfs1(e.to, u))
                return true;
        }
        return false;
    };
    pa[s] = 0;
    dfs1(s, 0);

    for (int u = t; u != 0; u = pa[u])
        path.push_back(u);
    reverse(path.begin(), path.end());

    for (int u : path)
        in_path[u] = true;

    ll ans = 0;
    for (int i = 1; i < (int)path.size(); i++) {
        ans += w_to_pa[path[i]];
    }

    function<ll(int)> dfs2 = [&](int u) {
        visited[u] = true;
        ll sum = 0;
        for (auto &e : g[u]) {
            int v = e.to;
            if (visited[v] || in_path[v])
                continue;
            ll gain = e.p + e.q;
            ll deeper = dfs2(v);
            if (gain + deeper > 0)
                sum += gain + deeper;
        }
        return sum;
    };
    for (int u : path) {
        ans += dfs2(u);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
