#include <bits/stdc++.h>
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

	vector<int> A, B;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') A.push_back(i + 1);
		else B.push_back(i + 1);
	}

	int Bmax = *max_element(B.begin(), B.end());
	bool has1   = find(B.begin(), B.end(), 1) != B.end();
	bool mid    = false;
	for (int x : B) {
		if (2 <= x && x <= n - 1) {
			mid = true;
			break;
		}
	}

	bool alice = false;
	for (int x : A) {
		if (x == 1) {
			if (!mid) {
				alice = true;
				break;
			}
		}
		else if (x == n) {
			if (!has1) {
				alice = true;
				break;
			}
		}
		else {
			if (Bmax <= x) {
				alice = true;
				break;
			}
		}
	}

	cout << (alice ? "Alice\n" : "Bob\n");
}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}