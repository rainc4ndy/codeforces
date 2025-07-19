#include <bits/stdc++.h>
#include <deque>
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
	int n, q;
	cin >> n >> q;
	vector<ll> v(n);
	vector<ll> ans(n);

	using R = array<ll, 4>;
	vector<R> req(q);
	deque<ll> dq;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		dq.eb(i);
	}
	for (int i = 0; i < q; i++) {
		cin >> req[i][0] >> req[i][1];
		req[i][2] = i;
	}

	ll mx = *max_element(all(v));

	sort(all(req), [&](auto & a, auto & b) {
		return a[1] < b[1];
	});

	ll k = 0;
	for (int i = 0; i < q; i++) {
		ll round = min(n - 1LL, req[i][1]);
		ll rem = req[i][1] - round;
		for (; k < round; k++) {
			auto a = dq.front();
			dq.pop_front();
			auto b = dq.front();
			dq.pop_front();

			if (v[a] > v[b]) {
				dq.emplace_front(a);
				ans[a]++;
				dq.eb(b);
			}
			if (v[a] < v[b]) {
				dq.emplace_front(b);
				ans[b]++;
				dq.eb(a);
			}
		}
		if (v[req[i][0] - 1] == mx) {
			req[i][3] = ans[req[i][0] - 1] + rem;
		} else {
			req[i][3] = ans[req[i][0] - 1];
		}
	}

	sort(all(req), [&](auto & a, auto & b) {
		return a[2] < b[2];
	});

	for (auto it : req) {
		cout << it[3] << endl;
	}
}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}