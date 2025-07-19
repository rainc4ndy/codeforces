#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
	string s;
	cin >> s;
	int cnt = 0;
	for (char c : s) {
		if (c == '(') {
			cnt++;
		} else {
			cnt = max(cnt - 1, 0ll);
		}
	}
	cout << (cnt ? "impossible" : s) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	int Test; cin >> Test; while (Test--)
		solve();
	return 0;
}
