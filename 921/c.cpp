#include <bits/stdc++.h>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;

ll v[mod];
ll mx = 0, mxi = 0;
bool check(ll x, ll n, ll sum) {
	ll r = sum + x;
	double average = (double)r / n;
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		if (mxi == i) {
			if (v[i] + x < average / 2) {
				cnt++;
			}
		} else {
			if (v[i] < average / 2) {
				cnt++;
			}
		}
	}
	return cnt > n / 2;
}

void solve() {
	ll n;
	cin >> n;

	ll sum = 0;
	mx = 0, mxi = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
		if (v[i] > mx) {
			mx = v[i], mxi = i;
		}
	}

	ll l = 0, r = 1e18, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid, n, sum)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << endl;
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
