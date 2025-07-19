#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof (arr))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define random rnd(chrono::system_clock::now().time_since_epoch().count())
#define setdb(v) setprecision(v)
#define debug(x) cout << #x << ' ' << x << endl;
#define x first
#define y second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const ll mod = 998244353;

void solve() {
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	// for (auto it : s) {
	// 	cout << (int ) it << ' ';
	// }
	// cout << endl;
	if (k == 0) {
		string s2 = s;
		reverse(begin(s2), end(s2));
		if (s < s2) {
			Yes;
		} else No;
	} else {
		if (s[0] < s[n - 1]) {
			Yes;
		} else if (s[0] == s[n - 1]) {
			for (int i = 1; i < n; i++) {
				if (s[i] != s[n - 1]) {
					Yes;
					return;
				}
			}
			No;
		} else {
			Yes;
		}
	}
}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}