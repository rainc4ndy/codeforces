#include <bits/stdc++.h>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll n;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	ll l = 0, r = n - 1;
	ll ans = 0;
	while (l < r) {
		ll area = min(v[l], v[r]) * (r - l);
		ans = max(ans, area);
		if (v[l] <= v[r]) {
			++l;
		}
		else {
			--r;
		}
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _ = 1;
	while (_--) solve();

	return 0;
}