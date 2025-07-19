#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdio>
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
const int maxn = 1e9 + 10;
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


ll arr[3001] {};
ll lowbit(ll x) {
	return x & (-x);
}
void add(ll p, ll x) {
	while (p <= 3000) {
		arr[p] += x;
		p = p + lowbit(p);
	}
}
ll getsum(ll p) {
	ll r = 0;
	while (p > 0) {
		r += arr[p];
		p = p - lowbit(p);
	}
	return r;
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> v(n), d(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++) cin >> d[i];

	vector<ll> g = v;
	sort_all(g);
	unq_all(g);
	auto get_id = [&](ll x) {
		return lower_bound(g.begin(), g.end(), x) - g.begin() + 1; // 下标从1开始
	};

	// 维护每个数最小的代价
	vector<ll> cost(3001, LONG_LONG_MAX);
	// 维护数的有序集合
	set<ll> ss;

	ll ans = LONG_LONG_MAX;
	bool ok = false;
	for (int i = n - 1; i >= 0; i--) {
		debug(v[i]);

		ll id = get_id(v[i]);

		add(id, 1);
		ss.insert(id);
		cost[id] = min(cost[id], d[i]);
		if (getsum(3000) - getsum(id) >= 3) {
			ok = true;
			vector<ll> tmp;
			for (auto it = next(lower_bound(all(ss), id)); it != ss.end(); it++) {
				tmp.eb(cost[*it]);
				debug(cost[*it]);
			}
			sort_all(tmp);
			ans = min(ans, d[i] + tmp[0] + tmp[1]);
		}
	}
	if (!ok) cout << -1;
	else cout << ans;
}

int main() {
	fastio;
	int _ = 1;
	while (_--) solve();

	return 0;
}