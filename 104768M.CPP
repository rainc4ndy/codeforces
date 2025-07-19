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
	int n;
	cin >> n;
	vector<ll> a(n), b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	auto check = [&](ll x) {
		vector<ll> pa(n);
		for (int i = 0; i < n; i++) {
			int con = 0;
			if (a[i] < x && b[i] >= x)      con = +1;
			else if (a[i] >= x && b[i] < x) con = -1;
			pa[i] = (i ? pa[i - 1] + con : con);
		}
		// base = 原始 a[i] >= x 的个数
		ll base = 0;
		for (int i = 0; i < n; i++)
			if (a[i] >= x) base++;

		// suf[i] = max(pa[i], pa[i+1], ..., pa[n-1])
		vector<ll> suf(n);
		suf[n - 1] = pa[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			suf[i] = max(pa[i], suf[i + 1]);
		}

		// 找最大增益
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			// 翻转区间 (i..j] 带来的增益 = suf[i] - pa[i]
			sum = max(sum, suf[i] - pa[i]);
		}

		// 只翻前缀
		for (int j = 0; j < n; j++) {
		    sum = max(sum, pa[j]);
		}
		return max(base, base + sum) >= ( (n + 1) / 2 );
	};


	ll l = 1, r = 1e9, mid, ans;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} else r = mid - 1;
	}
	cout << ans;
}

int main() {
	fastio;
	int _ = 1;
	//cin >> _;
	while (_--) solve();

	return 0;
}