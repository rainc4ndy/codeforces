#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_set>
#include <vector>
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
	int n;
	string s;
	cin >> n >> s;

	vector<int> v;
	for (int i = 1; i <= n / i; i++) {
		if (n % i == 0) {
			v.eb(i);
			if (i != n / i) {
				v.eb(n / i);
			}
		}
	}
	sort(all(v));

	for (int i = 0; i < v.size(); i++) {
		int sz = v[i];
		vector<vector<int>> d(sz, vector<int>(30));
		for (int j = 0; j < n; j++) {
			int p = j % sz;
			d[p][s[j]-'a']++;
		}

		string res(sz,0);
		for (int j = 0; j < sz; j++) {
			int mx = 0, mxi = 0;
			for (int k = 0; k < 26; k++) {
				if (d[j][k] > mx) {
					mxi = k;
					mx = d[j][k];
				}
			}
			res[j] = mxi+'a';
		}

		int bad = 0;
		for (int j = 0; j < n; j++) {
			int p = j % sz;
			if (res[p] != s[j]) {
				bad++;
			}
		}
		if (bad <= 1) {
			cout << sz << endl;
			return;
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