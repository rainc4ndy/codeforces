#include <array>
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

void solve() {
	ll n, m;
	cin >> n >> m;

	using Location = array<ll, 3>;
	using E = array<ll, 2>;
	using MyEdge = array<ll, 3>;

	vector<Location> v(n);
	vector<vector<pll>> graph(n, vector<pll>());
	vector<pll> beams(m);
	for (int i = 0; i < n; i++) {
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}

	for (int i = 0; i < m; i++) {
		ll x, y;
		cin >> x >> y;
		x--, y--;
		beams[i] = {x, y};
		graph[x].eb(y, i), graph[y].eb(x, i);
	}

	vector<MyEdge> e;
	for (int i = 0; i < n; i++) {
		int sz = graph[i].size();
		//边的数量至多m
		for (int j = 0; j < sz; ++j) {
			for (int k = j + 1; k < sz; ++k) {
				int id1 = graph[i][j].second;
				int id2 = graph[i][k].second;

				auto [a, b] = beams[id1];
				auto [c, d] = beams[id2];

				ll cost = min({
					abs(v[a][0] + v[b][0] - v[c][0] - v[d][0]),
					abs(v[a][1] + v[b][1] - v[c][1] - v[d][1]),
					abs(v[a][2] + v[b][2] - v[c][2] - v[d][2])
				});

				e.push_back({cost, id1, id2});
			}
		}
	}

	for (auto it : e) {
		debug(it[0]);
	}
}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}