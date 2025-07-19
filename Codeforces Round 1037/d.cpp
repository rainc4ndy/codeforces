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
#define debug1(x) RED; cout << #x << ' ' << x << endl; RESET;
#define debug2(x) GREEN; cout << #x << ' ' << x << endl; RESET;
#define debug3(x) BLUE; cout << #x << ' ' << x << endl; RESET;

constexpr int N = 3e5 + 7;

struct Tree {
	int mx, _mx;
	int ad, _ad;
	int st, _st;
} g[N * 4];

int a[N];
int n;
int L, R;

#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)

void pushup(int u) {
	g[u].mx = max(g[ls].mx, g[rs].mx);
	g[u]._mx = max(g[ls]._mx, g[rs]._mx);
}

void pushadd(int u, int v, int _v) {
	g[u]._mx = max(g[u]._mx, g[u].mx + _v);
	g[u].mx += v;
	if (g[u].st == INT_MIN) {
		g[u]._ad = max(g[u]._ad, g[u].ad + _v);
		g[u].ad += v;
	} else {
		g[u]._st = max(g[u]._st, g[u].st + _v);
		g[u].st += v;
	}
}

void pushset(int u, int v, int _v) {
	g[u]._mx = max(g[u]._mx, _v);
	g[u].mx = v;
	g[u]._st = max(g[u]._st, _v);
	g[u].st = v;
}

void pushdown(int u, int l, int r) {
	if (g[u].ad || g[u]._ad) {
		pushadd(ls, g[u].ad, g[u]._ad);
		pushadd(rs, g[u].ad, g[u]._ad);
		g[u].ad = g[u]._ad = 0;
	}
	if (g[u].st != INT_MIN || g[u]._st != INT_MIN) {
		pushset(ls, g[u].st, g[u]._st);
		pushset(rs, g[u].st, g[u]._st);
		g[u].st = g[u]._st = INT_MIN;
	}
}

void build(int u = 1, int l = 1, int r = n) {
	g[u].ad = g[u]._ad = 0;
	g[u]._st = g[u].st = INT_MIN;
	if (l == r) {
		g[u].mx = a[l];
		g[u]._mx = a[l];
		return;
	}
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(u);
}

void add(int v, int u = 1, int l = 1, int r = n) {
	if (R < l || r < L) return;
	if (L <= l && r <= R) {
		pushadd(u, v, max(v, 0));
		return;
	}
	pushdown(u, l, r);
	add(v, ls, l, mid);
	add(v, rs, mid + 1, r);
	pushup(u);
}

void tset(int v, int u = 1, int l = 1, int r = n) {
	if (R < l || r < L) return;
	if (L <= l && r <= R) {
		pushset(u, v, v);
		return;
	}
	pushdown(u, l, r);
	tset(v, ls, l, mid);
	tset(v, rs, mid + 1, r);
	pushup(u);
}

int qmax(int u = 1, int l = 1, int r = n) {
	if (R < l || r < L) return INT_MIN;
	if (L <= l && r <= R) return g[u].mx;
	pushdown(u, l, r);
	return max(qmax(ls, l, mid), qmax(rs, mid + 1, r));
}

int qmaxh(int u = 1, int l = 1, int r = n) {
	if (R < l || r < L) return INT_MIN;
	if (L <= l && r <= R) return g[u]._mx;
	pushdown(u, l, r);
	return max(qmaxh(ls, l, mid), qmaxh(rs, mid + 1, r));
}

void solve() {
	int m; ll k;
	cin >> m >> k;
	vector<array<ll, 3>> c(m);
	vector<ll> u;
	u.reserve(3 * m + 1);
	u.push_back(k);
	for (int i = 0; i < m; i++) {
		cin >> c[i][0] >> c[i][1] >> c[i][2];
		u.push_back(c[i][0]);
		u.push_back(c[i][1]);
		u.push_back(c[i][2]);
	}
	sort(u.begin(), u.end());
	u.erase(unique(u.begin(), u.end()), u.end());
	n = u.size();
	for (int i = 1; i <= n; i++) a[i] = u[i - 1];
	build();
	for (auto &e : c) {
		L = lower_bound(u.begin(), u.end(), e[0]) - u.begin() + 1;
		R = lower_bound(u.begin(), u.end(), e[1]) - u.begin() + 1;
		tset((int)e[2]);
	}
	ll cur = k;
	while (true) {
		int id = lower_bound(u.begin(), u.end(), cur) - u.begin() + 1;
		L = R = id;
		int best = qmaxh();
		if (best <= cur) break;
		cur = best;
	}
	cout << cur << '\n';
}

signed main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}