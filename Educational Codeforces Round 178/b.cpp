#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

#define int ll

struct Info {
	ll mx;
	Info() : mx(LLONG_MIN) {}
	Info(ll x) : mx(x) {}
	friend Info operator+(const Info &a, const Info &b) {
		return Info(max(a.mx, b.mx));
	}
};

struct SegmentTree {
	int n;
	vector<ll> tag;
	vector<Info> info;
	SegmentTree(int _n) : n(_n), tag(4 * n, 0), info(4 * n) {}

	void pull(int p) {
		info[p] = info[p << 1] + info[p << 1 | 1];
	}
	void apply(int p, ll v) {
		tag[p] += v;
		info[p].mx += v;
	}
	void push(int p) {
		if (tag[p]) {
			apply(p << 1, tag[p]);
			apply(p << 1 | 1, tag[p]);
			tag[p] = 0;
		}
	}
	void modify(int p, int l, int r, int idx, ll v) {
		if (l + 1 == r) {
			info[p] = Info(v);
			return;
		}
		int m = (l + r) >> 1;
		push(p);
		if (idx < m) modify(p << 1, l, m, idx, v);
		else         modify(p << 1 | 1, m, r, idx, v);
		pull(p);
	}
	void modify(int idx, ll v) { modify(1, 0, n, idx, v); }

	Info query(int p, int l, int r, int L, int R) {
		if (r <= L || R <= l) return Info();
		if (L <= l && r <= R) return info[p];
		int m = (l + r) >> 1;
		push(p);
		return query(p << 1, l, m, L, R)
		       + query(p << 1 | 1, m, r, L, R);
	}
	ll query(int L, int R) {
		return query(1, 0, n, L, R).mx;
	}
};

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	SegmentTree st(n);
	for (int i = 0; i < n; i++)
		st.modify(i, a[i]);

	vector<ll> suffix_sum(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		suffix_sum[i] = suffix_sum[i - 1] + a[n - i];
	}

	for (int k = 1; k <= n; k++) {
		ll tail_sum = suffix_sum[k - 1];
		ll mx = st.query(0, n - k + 1);
		cout << tail_sum + mx << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}
