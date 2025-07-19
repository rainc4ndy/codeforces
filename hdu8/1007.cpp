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

int lcm(int a, int b)
{
	int temp = a * b;
	temp = temp / __gcd(a, b);
	return temp;
}


void solve() {
	int n, m;
	cin >> n >> m;

	vector<pll> a(n), b(m);
	for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;

	for (int i = 0; i < m; i++) cin >> b[i].x >> b[i].y;

	ll L = b[0].y;
	for (int i = 1; i < m; i++) {
		L = lcm(L, b[i].y);
	}
	for (int i = 0; i < n; i++) {
		L = lcm(L, a[i].y);
	}


	for (int i = 0; i < n; i++) {
		ll mul = L / a[i].y;
		a[i].x *= mul;
		a[i].y = L;
	}
	for (int i = 0; i < m; i++) {
		ll mul = L / b[i].y;
		b[i].x *= mul;
		b[i].y = L;
	}

	map<pll, ll> mp;
	for (int i = 1; i < n; i++) {
		a[i].x += a[i - 1].x;
	}
	for (int i = 1; i < m; i++) {
		b[i].x += b[i - 1].x;
	}
	for (int i = 1; i < n; i++) {
		mp[ {a[i].x, a[i].y}]++;
	}
	for (int i = 1; i < m; i++) {
		mp[ {b[i].x, b[i].y}]++;
	}

	ll ans = 1;
	for (auto &it : mp) {
		if (it.second == 2)
			ans++;
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