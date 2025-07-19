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
	using Node = array<int, 4>;
	cin >> n;
	vector<Node> v(n);
	vector<pii> p(n);

	int up = 1e5, down = -1e5, left = -1e5, right = 1e5;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];

		if (!v[i][0])
			left = max(left, p[i].x);
		if (!v[i][1])
			up = min(up, p[i].y);
		if (!v[i][2])
			right = min(right, p[i].x);
		if (!v[i][3])
			down = max(down, p[i].y);
	}

	if (left <= right && down <= up) cout << 1 << ' ' << right << ' ' << up << endl;
	else cout << 0 << endl;
}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}