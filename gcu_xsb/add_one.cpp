#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

#define x first
#define y second

constexpr const int max_n = 200005, mod = 1000000007;

vector<ll> dp(200005);
void solve() {
	ll n,m;
	cin >> n >> m;

	ll ans = 0;
	while (n) {
		int v = n % 10;
		if (m + v < 10) {
			ans++;
		} else {
			int k = 10 - v;
			ans += dp[m-k];
			ans %= mod;
		}
		n /= 10;
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i <= max_n; i++) {
		if (i <= 8) dp[i] = 2;
		else if (i == 9) dp[i] = 3;
		else dp[i] = (dp[i-9] + dp[i-10]) % mod;
	}

	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}