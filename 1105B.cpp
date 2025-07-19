#include <bits/stdc++.h>
#include <cwchar>
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

	char lst = s[0];
	int con[512] {};
	int ans = k == 1 ? 1 : 0, cnt = 1;
	for (int i = 1; i < n; i++) {
		if (cnt >= k) {
			con[lst]++;
			ans = max(ans, con[lst]);
			cnt = 1;
		} else {
			if (s[i] == lst) {
				cnt++;
			} else {
				cnt = 1;
			}
		}
		lst = s[i];
	}
	if (cnt >= k) {
		con[lst]++;
		ans = max(ans, con[lst]);
		cnt = 1;
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _ = 1;
	while (_--) solve();

	return 0;
}