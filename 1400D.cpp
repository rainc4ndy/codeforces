#include <algorithm>
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
	cin >> n;
	vector<int> a(n);
	unordered_map<int, vector<int>> pos;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pos[a[i]].push_back(i);
	}

	ll ans = 0;
	for (int j = 0; j < n; ++j) {
		for (int k = j + 1; k < n; ++k) {
			int val_ik = a[k];
			int val_jl = a[j];
			// 多少 i < j 满足 a[i] == a[k]
			const auto& vec_ik = pos[val_ik];
			int left = lower_bound(vec_ik.begin(), vec_ik.end(), j) - vec_ik.begin();
			// 多少 l > k 满足 a[l] == a[j]
			const auto& vec_jl = pos[val_jl];
			int right = vec_jl.end() - lower_bound(vec_jl.begin(), vec_jl.end(), k + 1);

			ans += 1LL * left * right;
		}
	}

	cout << ans << '\n';
}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}