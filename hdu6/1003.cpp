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

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n+1), b(n+1), pa(n+1), sum(n+1);

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	for (int i = 1; i <= n; i++) {
		pa[i] = pa[i-1] + a[i];
		sum[i] = a[i] + b[i];
	}

	ll ans = 0;
	int l = 1, r = l;
	while (l <= n) {
		r = l;
		while (r + 1 <= n && sum[r + 1] == sum[l]) r++;
		ll ta = pa[r] - pa[l - 1];
		ll len = r - l + 1;
		ans = max(ans, ta * len);
		l = r + 1;
	}
	cout << ans << '\n';
}

int main() {    
	fastio;
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
