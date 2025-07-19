#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	ll ans = 0;
	for (int i = 1; i < n; i++) {
		if (v[i] < v[i - 1]) {
			ll delta = v[i - 1] - v[i];
			ll bits = 0;
			while ((1LL << bits) <= delta) bits++;
			ans = max(ans, bits);
			v[i] = v[i - 1]; // 保证后面判断成立，但不影响结果
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
