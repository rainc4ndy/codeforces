#include <bits/stdc++.h>
#include <numeric>
#include <utility>
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

class dsu {
public:
	vector<int> pa;
	dsu() {
		pa.resize(1024);
		iota(all(pa), 0);
	}
	int find(int x) {
		return pa[x] == x ? x : (pa[x] = find(pa[x]));
	}
	void unite(int x, int y) {
		pa[find(x)] = find(y);
	}
};

void solve() {
	int n;
	int m1, m2;
	cin >> n >> m1 >> m2;

	dsu d1, d2;
	rep(m1) {
		int x, y;
		cin >> x >> y;
		d1.unite(x, y);
	}
	rep(m2) {
		int x, y;
		cin >> x >> y;
		d2.unite(x, y);
	}

	// 连通块数量
	int c1 = 0, c2 = 0;
	for (int i = 1; i <= n; i++) {
		c1 += d1.find(i) == i;
		c2 += d2.find(i) == i;
	}
	// 需要保证d1的连通块是最多的
	if (c2 > c1) {
		swap(d1, d2);
	}

	vector<pii> ans;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {  // j>i avoids duplicates
			if (d1.find(i) != d1.find(j)
			        && d2.find(i) != d2.find(j))
			{
				ans.emplace_back(i, j);
				d1.unite(i, j);
				d2.unite(i, j);
			}
		}
	}


	cout << ans.size() << endl;
	for (auto it : ans) cout << it.x << ' ' << it.y << endl;
}

int main() {
	fastio;

	int _ = 1;
	while (_--) solve();

	return 0;
}