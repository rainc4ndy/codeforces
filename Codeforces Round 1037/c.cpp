#include <bits/stdc++.h>
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
#define debug1(x) RED; cout << #x << ' ' << x << endl; RESET;
#define debug2(x) GREEN; cout << #x << ' ' << x << endl; RESET;
#define debug3(x) BLUE; cout << #x << ' ' << x << endl; RESET;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<ll> h(n + 1);
	ll Hmax = 0;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		Hmax = max(Hmax, h[i]);
	}
	vector<ll> dist(n + 1, LONG_LONG_MAX);
	dist[k] = 0;
	priority_queue<pair<ll, int>,vector<pair<ll, int>>,greater<pair<ll, int>>> pq;
	pq.emplace(0, k);
	set<pair<ll, int>> S;
	for (int i = 1; i <= n; i++) {
		if (i != k)
			S.emplace(h[i], i);
	}
	bool ok = false;
	while (!pq.empty()) {
		auto [t, u] = pq.top();
		pq.pop();
		if (t > dist[u]) continue;
		if (h[u] == Hmax) {
			ok = true;
			break;
		}
		ll lo = t;
		ll hi = 2 * h[u] - t;
		auto it = S.lower_bound({ lo, -1 });
		while (it != S.end() && it->x <= hi) {
			int v = it->y;
			ll w  = abs(h[u] - h[v]);
			ll nt = t + w;
			if (nt <= h[u] && nt <= h[v] && nt < dist[v]) {
				dist[v] = nt;
				pq.emplace(nt, v);
			}
			it = S.erase(it);
		}
	}

	cout << (ok ? "YES\n" : "NO\n");
}

signed main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}