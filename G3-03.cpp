#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll l, n, k;
	cin >> l >> n >> k;
	vector<ll> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	auto check = [&](ll x) -> bool {
		//第一个宾客坐的位置
		for (ll i = 0; i < n; i++) {
			
		}
		//cout << "mi = " << mi << endl;
		return  >= x;
	};


	ll L = 1, R = 1e9, mid, ans;
	while (L <= R) {
		mid = (L+R)>>1;
		if (check(mid)) {
			L = mid+1;
			ans = mid;
		} else {
			R = mid-1;
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