#include <bits/stdc++.h>
#include <iterator>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	string s;
	cin >> s;

	char lst = s[0];
	int cnt = 1;
	int ans = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == lst) {
			cnt++;
		} else {
			ans += cnt - 1;
			cnt = 1;
		}
		lst = s[i];
	}
	if (cnt > 1) {
		ans += cnt - 1;
	}

	if (s[0] == 'o')
		ans++;

	if ((ans + s.size()) & 1) ans++;

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