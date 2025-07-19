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
const int maxn = 2e5 + 10;
const ll mod = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	for (ll &x : a) {
		cin >> x;
		sum += x;
	}

	for (int i = n; i >= 1; i--) {
		if (sum % i == 0) {
			ll needSum = sum / i;
			ll curSum = 0;
			bool ok = true;
			for (int j = 0; j < n; j++) {
				curSum += a[j];
				if (curSum > needSum) {
					ok = false;
					break;
				} else if (curSum == needSum) {
					curSum = 0;
				}
			}

			if (ok) {
				cout << n - i << endl;
				return;
			}
		}
	}
}

int main() {
	int tests;
	cin >> tests;
	while (tests-- > 0) {
		solve();
	}
	return 0;
}