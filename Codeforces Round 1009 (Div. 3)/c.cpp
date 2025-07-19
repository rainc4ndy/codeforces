#include <bits/stdc++.h>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

ll myXOR(ll x, ll y) {
	ll res = 0;

	for (ll i = 31; i >= 0; i--)
	{
		bool b1 = x & (1 << i);
		bool b2 = y & (1 << i);

		bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);

		res <<= 1;
		res |= xoredBit;
	}
	return res;
}


void solve() {
	ll x;
	cin >> x;
	auto check = [&](ll y) -> bool {
		ll d = myXOR(y, x);
		if (x + y > d && 
			y + d > x &&
			x + d > y 
			) {
			return true;
		}
		return false;
	};

	ll l = 1, r = x-1, ans = -1;
	while (l <= r) {
		long long mid = (l + r) >> 1;
		if (check(mid))
			r = (ans = mid) - 1;
		else
			l = mid + 1;
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}