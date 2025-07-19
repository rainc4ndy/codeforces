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

const int N = 2e5 + 9;
const int M = 10007;

void solve() {
	int k, c, d, e, f; std::cin >> k >> c >> d >> e >> f;

	std::vector<int> ci(16);

	ci[0] = 1;
	for (int i = 1; i <= 15; i ++) {
		ci[i] = (ci[i - 1] * 10) % M;
	}

	int ans = 0;
	std::vector<int> tmp;
	for (int i = 0; i < M; i ++) {
		tmp.clear();
		__int128_t now = c * i * i * i + d * i * i + e * i + f;

		while (now) {
			tmp.push_back((int)(now % 27));
			now /= 27;
		}

		// tmp.size() 即为字符的个数
		// 实际上我们不关心字符具体是什么
		if (tmp.size() > k)continue;
		if (tmp.size() == 0)continue;

		bool ck = false;
		int p = 0;
		for (int i = 0; i < tmp.size(); i ++) {
			if (tmp[i] == 0)ck = true;
			p = (p + tmp[i] * ci[i]) % M;
		}

		if (ck)continue;
		if (p == i) {
			ans ++;
		}
	}

	std::cout << ans << '\n';
}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}