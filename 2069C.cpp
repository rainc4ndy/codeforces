#include <algorithm>
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

constexpr int P = mod;
constexpr int L = 2e5;
int fac[L + 1], invfac[L + 1];
int sumbinom[L + 1][7];

int binom(int n, int m) {
	if (n < m || m < 0) {
		return 0;
	}
	return 1LL * fac[n] * invfac[m] % P * invfac[n - m] % P;
}
int power(int a, int b) {
	int res = 1;
	for (; b; b /= 2, a = 1LL * a * a % P) {
		if (b % 2) {
			res = 1LL * res * a % P;
		}
	}
	return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    ll cnt1 = 0, cnt2 = 0;
    ll ans = 0;
    for (int x : a) {
        if (x == 1) cnt1++;
        else if (x == 2) cnt2++;
        else if (x == 3) {
            if (cnt1 > 0) {
                ans = (ans + cnt1 * (power(2, cnt2)-1)) % mod;
            }
        }
    }
    cout << ans << '\n';
}


int main() {
	fac[0] = 1;
	for (int i = 1; i <= L; i++) {
		fac[i] = 1LL * fac[i - 1] * i % P;
	}
	invfac[L] = power(fac[L], P - 2);
	for (int i = L; i; i--) {
		invfac[i - 1] = 1LL * invfac[i] * i % P;
	}
	sumbinom[0][0] = 1;
	for (int i = 1; i <= L; i++) {
		for (int j = 0; j < 7; j++) {
			sumbinom[i][j] = (sumbinom[i - 1][j] + sumbinom[i - 1][(j + 6) % 7]) % P;
		}
	}

	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}