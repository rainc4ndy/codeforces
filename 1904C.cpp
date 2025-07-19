#include <bits/stdc++.h>
using namespace std;

const int mod = 2e3 + 10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

ll a[mod];
void solve() {
	ll n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> a[i];
	if (k >= 3) {
		cout << 0 << endl;
		return;
	}

	std::sort(a, a+n);

	ll d = a[0];
	for (int i = 0; i < n - 1; i++) {
		d = min(d, a[i + 1] - a[i]);
	}

	if (k == 1) {
		cout << d << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			ll v = a[i] - a[j];
			ll p = lower_bound(a, a+n, v) - a;
			if (p < n) d = min(d, a[p] - v);
			if (p > 0) d = min(d, v - a[p - 1]);
		}
	}
	cout << d << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}