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


struct Node {
	int len;
	int pre0, suf0, best0;
	int pre1, suf1, best1;
	bool flip;
	Node(): len(0), pre0(0), suf0(0), best0(0), pre1(0), suf1(0), best1(0), flip(false) {}
};

struct SegmentTree {
	int n;
	vector<Node> st;
	SegmentTree(const string &s) {
		n = s.size();
		st.resize(4 * n);
		build(1, 1, n, s);
	}
	void build(int p, int l, int r, const string &s) {
		Node &o = st[p];
		o.len = r - l + 1;
		if (l == r) {
			if (s[l - 1] == '0') {
				o.pre0 = o.suf0 = o.best0 = 1;
			} else {
				o.pre1 = o.suf1 = o.best1 = 1;
			}
			return;
		}
		int m = (l + r) >> 1;
		build(p << 1, l, m, s);
		build(p << 1 | 1, m + 1, r, s);
		pull(p);
	}
	void apply_flip(int p) {
		Node &o = st[p];
		swap(o.pre0, o.pre1);
		swap(o.suf0, o.suf1);
		swap(o.best0, o.best1);
		o.flip = !o.flip;
	}
	void push(int p) {
		if (st[p].flip) {
			apply_flip(p << 1);
			apply_flip(p << 1 | 1);
			st[p].flip = false;
		}
	}
	void pull(int p) {
		Node &o = st[p];
		Node &L = st[p << 1], &R = st[p << 1 | 1];
		o.pre0 = L.pre0 == L.len ? L.len + R.pre0 : L.pre0;
		o.pre1 = L.pre1 == L.len ? L.len + R.pre1 : L.pre1;
		o.suf0 = R.suf0 == R.len ? R.len + L.suf0 : R.suf0;
		o.suf1 = R.suf1 == R.len ? R.len + L.suf1 : R.suf1;
		o.best0 = max({L.best0, R.best0, L.suf0 + R.pre0});
		o.best1 = max({L.best1, R.best1, L.suf1 + R.pre1});
	}
	void update_flip(int p, int l, int r, int i, int j) {
		if (j < l || r < i) return;
		if (i <= l && r <= j) {
			apply_flip(p);
			return;
		}
		push(p);
		int m = (l + r) >> 1;
		update_flip(p << 1, l, m, i, j);
		update_flip(p << 1 | 1, m + 1, r, i, j);
		pull(p);
	}

	int find_first(int p, int l, int r, int op, int k) {
		Node &o = st[p];
		int best = (op == 0 ? o.best0 : o.best1);
		if (best < k) return -1;
		if (l == r) return l;
		push(p);
		int m = (l + r) >> 1;
		Node &L = st[p << 1];
		int left_best = (op == 0 ? L.best0 : L.best1);
		if (left_best >= k) {
			return find_first(p << 1, l, m, op, k);
		}
		int l_suf = (op == 0 ? L.suf0 : L.suf1);
		int r_pre = (op == 0 ? st[p << 1 | 1].pre0 : st[p << 1 | 1].pre1);
		if (l_suf + r_pre >= k) {
			return m - l_suf + 1;
		}
		return find_first(p << 1 | 1, m + 1, r, op, k);
	}
};

void solve() {
	string S;
	cin >> S;
	SegmentTree st(S);
	int q;
	cin >> q;
	while (q--) {
		int op, k;
		cin >> op >> k;
		int pos = st.find_first(1, 1, S.size(), op, k);
		if (pos == -1) {
			cout << -1 << '\n';
		} else {
			cout << pos << '\n';
			st.update_flip(1, 1, S.size(), pos, pos + k - 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
