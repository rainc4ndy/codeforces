#include <bits/stdc++.h>
#include <climits>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll n, b, c;
	cin >> n >> b >> c;

	if (b == 0) {
		if (c >= n) {
			cout << n << endl;
		} else if (c >= n - 2) {
			cout << n - 1 << endl;
		} else {
			cout << -1 << endl;
		}
	} else {
		if (c >= n) {
			cout << n << endl;
		} else {
			ll cl = n - max(0ll, 1 + (n - c - 1) / b);
			cout << cl << endl;
		}
	}
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