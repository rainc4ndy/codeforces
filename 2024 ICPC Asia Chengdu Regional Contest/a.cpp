#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void solve() {
	ll a,b,c;
	cin >> a >> b >> c;

	cout << 100 << endl;
	for (int i = 0; i < 50; i++) {
		cout << a << ' ';
	}

	for (int i = 0; i < 45; i++) {
		cout << b << ' ';
	}

	for (int i = 0; i < 4; i++) {
		cout << c << ' ';
	}

	cout << c + 1;
}

int main() {

	int _ = 1;
	//cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}