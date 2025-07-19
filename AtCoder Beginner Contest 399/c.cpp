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
const int maxn = 2e5+10;
const ll mod = 998244353;

struct dsu {
    std::vector<int> pa;

    explicit dsu(int size) : pa(size) {
        std::iota(pa.begin(), pa.end(), 0);
    }

    int find(int x) {
        return pa[x] == x ? x : (pa[x] = find(pa[x]));
    }

    void unite(int x, int y) {
        pa[find(x)] = find(y);
    }
};

void solve() {
	int n,m;
	cin >> n >> m;
	
	int ans = 0;

	dsu d(n+1);
	for (int i = 0; i < m; i++) {
		int x,y;
		cin >> x >> y;
		if (d.find(x) == d.find(y)) {
			ans++;
		}
		d.unite(x, y);
	}
	cout << ans << endl;
}

int main() {    
    fastio;
	int _ = 1;
	while(_--) solve();

	return 0;
}