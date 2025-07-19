#include <bits/stdc++.h>
using namespace std;

const int mod = 1e6 + 10;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ull x;

	cin >> x;

	ull l = 1, r = x;
	ull mid ;
	ull p1,p2;
	while (l <= r) {
		mid = (l+r)>>1;
		p1 = __gcd(mid, x), p2 = (mid ^ x);
		if (p1 == p2) {
			cout << mid << endl;
			return;
		}
		if (p1 > p2) {
			r = mid-1;
		} else {
			l = mid+1;
		}
	}
	cout << -1 << endl;
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