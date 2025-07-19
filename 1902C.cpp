#include <bits/stdc++.h>
#include <cwchar>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

ll v[mod] {};
ll pa[mod] {};

void solve() {
	int n;
	cin >> n;

	ll mx = -1e9 - 10;
	ll mi = 1e9 + 10;
	set<ll> s;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mx = max(mx, v[i]);
		mi = min(mi, v[i]);
		s.insert(v[i]);
	}

	// 若要让步骤尽可能的小，则需要让全体元素通过尽可能少的步骤增长到最大值
	// 则可以考虑GCD

	//1: 如果a[n+1]的值存在并小于最大值，则可以通过选取区间内的值来使得步骤最小
	
	for (int i = 0; i < n; i++) {
		pa[i] = mx - v[i];
	}

	if (n == 1) {
		cout << 1 << endl;
	} else {
		ll g = pa[0];
		for (int i = 1; i < n; i++) {
			g = __gcd(g, pa[i]);
		}

		ll val = 0;
		for (int k = -1; k >= -1e9; k--) {
			if (!s.count(mx+k*g)) {
				val = mx+k*g;
				break;
			}
		}

		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ans += pa[i] / g;
		}
		ans += (mx - val) / g;
		cout << ans << endl;
	}
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