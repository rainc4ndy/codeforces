#include <bits/stdc++.h>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

ll v[mod];

void solve() {
	ll n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v, v + n);
	int l = 0, r = 0;
	ll ans = 0;
	ll sum = 0;
	while (r <= n) {
		r++;
		if (v[r] - v[l] > 1) {
			while (v[r] - v[l] > 1) {
				sum -= v[l];
				l++;
			}
			ans = max(ans, sum);
			continue;
		}

		sum += v[r];
		if (sum >= m) {
			l = r;
			ans = m;
			sum = 0;
			break;
		}
		ans = max(ans, sum);
		if (ans >= m) {
			ans = m;
			break;
		}
		r++;
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t ;
	cin >> t;
	while (t--) solve();

	return 0;
}