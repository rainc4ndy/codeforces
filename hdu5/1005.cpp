#include <bits/stdc++.h> 
#include <iomanip>
#include <ios>
#include <vector>
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

void solve() {
	ll p,n,k;
	cin >> p >> n >> k;

	vector<pll> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y;
	}
	
	double ans = 1e9+10;
	vector<bool> vis(n);
	auto dfs = [&](auto const& self, ll id, ll step, double cur) -> double {
		if (vis[id])
			return 1e9+10;
		if (step >= k) {
			return cur;
		}
		vis[id] = true;
		double r = 1e9+10;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				if (v[i].x == 0)
					r = min(r, self(self, i, step+1, cur * v[i].y / 10));
				else 
					r = min(r, self(self, i, step+1, cur - v[i].y));
				vis[i] = false;
			}
		}
		return r;
	};

	for (int i = 0; i < n; i++) {
		ans = min(ans, dfs(dfs, i, 0, p));
		vis[i] = false;
	}

	cout << fixed << setprecision(2) << max(0.0, ans) << endl; 
}

int main() {    
    fastio;
	int _;
	cin >> _;
	while(_--) solve();

	return 0;
}