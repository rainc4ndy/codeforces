#include <algorithm>
#include <bits/stdc++.h>
#include <set>
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

/*
1
9 5
3 5 2 3 3 5 8 1 2
4 6 2 4 6
*/
void solve() {
	int n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	int cur = 0;
	for (int i = 0; i < n && cur < m; i++) {
		if (a[i] >= b[cur]) cur++;
	}
	if (cur == m) {
		cout << 0 << "\n";
		return;
	}

	auto can = [&](ll k) {
		int dp0 = 0;
		int dp1 = -1000000000; 
		for (int i = 0; i < n; i++) {
			if (dp0 < m && k >= b[dp0]) {
				dp1 = max(dp1, dp0 + 1);
			}
			if (dp0 < m && a[i] >= b[dp0]) {
				dp0++;
			}
			if (dp1 < m && dp1 >= 0 && a[i] >= b[dp1]) {
				dp1++;
			}
		}
		if (dp0 < m && k >= b[dp0]) {
			dp1 = max(dp1, dp0 + 1);
		}
		return (dp1 >= m);
	};

	ll lo = 1, hi = 1000000000, ans = -1;
	while (lo <= hi) {
		ll mid = lo + ((hi - lo) >> 1);
		if (can(mid)) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << ans << "\n";
}
int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}