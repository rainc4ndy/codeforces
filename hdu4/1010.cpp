#include <bits/stdc++.h>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;
#define int ll

void solve() {
	int n, m;
	cin >> n >> m;
	ll Umin = LLONG_MAX, Umax = LLONG_MIN;
	ll Vmin = LLONG_MAX, Vmax = LLONG_MIN;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		ll U = x + y;
		ll V = x - y;
		Umin = min(Umin, U);
		Umax = max(Umax, U);
		Vmin = min(Vmin, V);
		Vmax = max(Vmax, V);
	}
	ll ans = LLONG_MAX;
	for (int j = 0; j < m; j++) {
		ll a, b;
		cin >> a >> b;
		ll U0 = a + b;
		ll V0 = a - b;
		ll d1 = Umax - U0;
		ll d2 = U0 - Umin;
		ll d3 = Vmax - V0;
		ll d4 = V0 - Vmin;
		ll d = max(max(d1, d2), max(d3, d4));
		ans = min(ans, d);
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
