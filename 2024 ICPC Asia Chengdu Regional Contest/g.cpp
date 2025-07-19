#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define debug(x) cout << #x << ' ' << x << endl

void solve() {
	ll n;
	cin >> n;
	vector<ll> v(n + 1);
	int res = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		res |= v[i];
	}
	int cnt = __builtin_popcount(res);

	ll ans = 1LL << cnt;
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int _ = 1;
	// cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}