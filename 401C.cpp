#include <bits/stdc++.h>
using namespace std;

#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof (arr))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define random rnd(chrono::system_clock::now().time_since_epoch().count())
#define setdb(v) setprecision(v)
#define all(x) x.begin(), x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define sort_all(x) sort(all(x))
#define reverse_all(x) reverse(all(x))
#define x first
#define y second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
#define pb push_back
#define eb emplace_back
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const ll mod = 998244353;
#define RED cout << "\033[91m"
#define GREEN cout << "\033[92m"
#define YELLOW cout << "\033[93m"
#define BLUE cout << "\033[94m"
#define MAGENTA cout << "\033[95m"
#define CYAN cout << "\033[96m"
#define RESET cout << "\033[0m"
#define debug(x) cout << #x << ' ' << x << endl;
#define debug1(x)                     \
    RED;                              \
    cout << #x << ' ' << x << endl; \
    RESET;
#define debug2(x)                     \
    GREEN;                            \
    cout << #x << ' ' << x << endl; \
    RESET;
#define debug3(x)                     \
    BLUE;                             \
    cout << #x << ' ' << x << endl; \
    RESET;

void solve() {
	int n, m;
	// 0, 1
	cin >> n >> m;

	string s;
	s.resize(n+m);

	int c0 = n, c1 = m;
	int cnt = 0, pre = -1;
	for (int i = 0; i < n+m;) {
		if (c1 >= 2) {
			c1 -= 2;
			s[i] = s[i+1] = '1';
			i += 2;

			if (pre == s[i]) {
				cnt++;
				if (cnt >= 3) {
					cout << -1;
					return;
				}
			} else {
				cnt = 1;
			}
			pre = s[i];
		} else if (c1 == 1) {
			s[i] = '1';
			c1--;
			i++;

			if (pre == s[i]) {
				cnt++;
				if (cnt >= 3) {
					cout << -1;
					return;
				}
			} else {
				cnt = 1;
			}
			pre = s[i];
		}
		if (c0 >= 1) {
			s[i] = '0';
			c0--;
			i++;

			if (pre == s[i]) {
				cnt++;
				if (cnt >= 2) {
					cout << -1;
					return;
				}
			} else {
				cnt = 1;
			}
			pre = s[i];
		}
	}
	cout << s;
}

int main() {
	fastio;
	int _ = 1;
	while (_--) solve();

	return 0;
}