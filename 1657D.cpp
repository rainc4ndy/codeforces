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
	ll n, c;
	cin >> n >> c;

	vector<array<ll, 3>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}
	sort(all(v), [&](array<ll, 3>&a, array<ll, 3>&b){
		if (a[0] == b[0]) {
			return a[1]*a[2] > b[1]*b[2];
		}
		return a[0] < b[0];
	});

	ll m; cin >> m;
	vector<array<ll, 2>> d(m);
	for (int i = 0; i < m; i++) {
		cin >> d[i][0] >> d[i][1];
	}

	// // 找到第一个可购买的单位，且价值最小的单位的下标
	// auto find = [&](ll cost) -> int {
	// 	int l = 0, r = v.size() - 1, mid, ans = -1;
	// 	while (l <= r) {
	// 		mid = (l + r) >> 1;
	// 		if (v[mid][0] <= cost) {
	// 			l = mid + 1;
	// 			ans = mid;
	// 		} else {
	// 			r = mid - 1;
	// 		}
	// 	}
	// 	return ans;
	// };

	// auto check = [&](ll u, int di) -> bool {
	// 	ll D = d[di][0], H = d[di][1];
	// 	ll lim = min(c, u);
	// 	int vid = find(lim);
	// 	if (vid == -1) return false;

	// 	for (int i = 0; i <= vid; i++) {
	// 		ll ci = v[i][0];
	// 		ll di = v[i][1];
	// 		ll hi = v[i][2];

	// 		ll maxK = lim / ci;
	// 		ll dmg_per_unit = di * hi;

	// 		if (dmg_per_unit == 0) continue;

	// 		// H * D / dmg_per_unit 向上取整，再加 1 保证严格大于
	//     	ll minK = (H * D + dmg_per_unit) / dmg_per_unit;

	// 		if (minK <= maxK) return true;
	// 	}
	// 	return false;
	// };

	auto check = [&](ll u, int di) -> bool {
		ll D = d[di][0], H = d[di][1];
		ll lim = min(c, u);

		int l = 0, r = v.size() - 1, mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (v[mid][0] <= lim) {
				l = mid + 1;
				ll ci = v[mid][0];
				ll di = v[mid][1];
				ll hi = v[mid][2];

				ll maxK = lim / ci;
				debug(di * hi * maxK);
				if (H * D < di * hi * maxK) return true;
				else {
					r = mid - 1;
				}
			} else {
				r = mid - 1;
			}
		}
		return false;
	};


	for (int i = 0; i < m; i++) {
		ll l = 0, r = 1e6 + 10, mid, ans = -1;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (check(mid, i)) {
				r = mid - 1;
				ans = mid;
			} else {
				l = mid + 1;
			}
		}
		cout << ans << ' ';
	}
}

int main() {
	fastio;
	int _ = 1;
	while (_--) solve();

	return 0;
}