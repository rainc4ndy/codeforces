#include <bits/stdc++.h>
#include <queue>
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

/*
1
7 4
3 1 5 2 7 6 4
3 4 2
2 3 5
1 5 6
1 7 3
*/
void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n + 1), d(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++) {
		d[v[i]] = i;
	}

	for (int i = 0; i < q; i++) {
		int l, r, k;
		cin >> l >> r >> k;
		int id = d[k];
		if (l <= id && id <= r) {
			int lo = l, hi = r, mid;
			int req_smaller = 0, req_bigger = 0;
			int small = k - 1, big = n - k;
			while (lo <= hi) {
				mid = (lo + hi) >> 1;
				if (mid < id) {
					lo = mid + 1;
					if (v[mid] > k) req_smaller++;
					else small--; //used;
				} else if (mid > id) {
					hi = mid - 1;
					if (v[mid] < k) req_bigger++;
					else big--; //used;
				} else {
					break;
				}
			}
			// debug(req_smaller);
			// debug(req_bigger);
			// debug(small);
			// debug(big);
			if (req_smaller > small || req_bigger > big) {
				cout << -1 << ' ';
			} else {
				cout << 2 * max(req_smaller, req_bigger) << ' ';
			}
		} else {
			cout << -1 << ' ';
		}
	}
	cout << endl;
}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}