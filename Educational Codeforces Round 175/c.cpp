#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	auto check = [&](ll x) {
		// can we reach the condtion greedyly within X penalty?
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] > x && s[i] == 'B') {
				int j = i+1;
				while (j < n && (s[j] == 'B' || v[j] <= x)) j++;
				i = j-1;
				cnt++;
			}
		}
		return cnt <= k;
	};

	ll l = 0, r = *std::max_element(begin(v), end(v)), mid = 0, ans = 0;

	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
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

	int _;
	cin >> _;
	while (_--)
		solve();

	return 0;
}