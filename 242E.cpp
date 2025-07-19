#include <bits/stdc++.h>
#include <bitset>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vb = vector<bool>;
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
#define nin ll n; cin >> n
//.........Bit_Manipulation...........//
#define msb(mask) (63-__builtin_clzll(mask))
#define lsb(mask) __builtin_ctzll(mask)
#define cntsetbit(mask) __builtin_popcount(mask)
#define checkbit(mask,bit) ((mask >> bit) & 1ll)
#define onbit(mask,bit) ((mask)|(1LL<<(bit)))
#define offbit(mask,bit) ((mask)&~(1LL<<(bit)))
#define changebit(mask,bit) ((mask)^(1LL<<bit))
#define setbit(mask,bit) ((mask)|(1LL<<(bit)))
#define resetbit(mask,bit) ((mask)&~(1LL<<(bit)))
#define togglebit(mask,bit) ((mask)^(1LL<<bit))
//.........Fast Input...........//
inline void read(int &a) { cin >> a; }
inline void read(ll &a) { cin >> a; }
inline void read(char &a) { cin >> a; }
inline void read(double &a) { cin >> a; }
inline void read(long double &a) { cin >> a; }
inline void read(string &a) { cin >> a; }
template<class T, class S>
void read(pair<T, S> &p) {
	read(p.first), read(p.second);
}
template<class T>
void read(vector<T> &a) {
	for (auto &i : a) read(i);
}
template<class T>
void read(T &a) {
	cin >> a;
}
#define TIME cout<<(double)clock()/CLOCKS_PER_SEC <<"ms"<<endl;
#define debug(x) cout << #x << ' ' << x << endl;
const int maxn = 2e5 + 10;
const ll mod = 998244353;

//维护1的个数
struct Info {
	ll sum;
	Info() : sum(0) {}
	Info(ll x) : sum(x) {}
	friend Info operator+(const Info &a, const Info &b) {
		return Info(a.sum + b.sum);
	}
};
struct SegmentTree {
	int n;
	vector<ll> tag; //lazyFlip
	vector<Info> info;
	SegmentTree(int _n) : n(_n), tag(4 * n, 0), info(4 * n) {}

	void pull(int p) {
		info[p] = info[p << 1] + info[p << 1 | 1];
	}
	void apply(int p, int len) {
		tag[p] ^= 1;
		info[p].sum = len - info[p].sum;
	}
	void push(int p, int l, int r) {
		if (tag[p]) {
			int m = (l + r) >> 1;
			apply(p << 1, m - l);
			apply(p << 1 | 1, r - m);
			tag[p] = 0;
		}
	}

	void modify(int p, int l, int r, int idx, ll v) {
		if (l + 1 == r) {
			info[p] = Info(v);
			return;
		}
		int m = (l + r) >> 1;
		push(p, l, r);
		if (idx < m) modify(p << 1, l, m, idx, v);
		else         modify(p << 1 | 1, m, r, idx, v);
		pull(p);
	}
	void modify(int idx, ll v) { modify(1, 0, n, idx, v); }

	void rangeFlip(int p, int l, int r, int L, int R) {
		if (r <= L || R <= l) return;
		if (L <= l && r <= R) {
			apply(p, r - l);
			return;
		}
		push(p, l, r);
		int m = (l + r) >> 1;
		rangeFlip(p << 1, l, m, L, R);
		rangeFlip(p << 1 | 1, m, r, L, R);
		pull(p);
	}
	void rangeFlip(int L, int R) { rangeFlip(1, 0, n, L, R); }

	Info query(int p, int l, int r, int L, int R) {
		if (r <= L || R <= l) return Info();
		if (L <= l && r <= R) return info[p];
		push(p, l, r);
		int m = (l + r) >> 1;
		return query(p << 1, l, m, L, R)
		       + query(p << 1 | 1, m, r, L, R);
	}
	ll querySum(int L, int R) {
		return query(1, 0, n, L, R).sum;
	}
};

void solve() {
	nin;
	vector<int> v(n); read(v);

	vector<SegmentTree> tr;
	for (int i = 0; i < 32; i++) tr.pb(SegmentTree(n));

	for (int i = 0; i < n; i++) {
		bitset<32> bs(v[i]);
		for (int j = 0; j < 32; j++) {
			if (bs[j])
				tr[j].modify(i, 1);
		}
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int op; cin >> op;
		if (op == 1) {
			int l, r;
			cin >> l >> r;
			l--, r--;
			ll res = 0;
			for (int j = 0; j < 32; j++) {
				auto num = tr[j].querySum(l, r + 1);
				if (num)
					res += num * (1 << j);
			}
			cout << res << endl;
		} else {
			int l, r, x;
			cin >> l >> r >> x;
			l--, r--;
			bitset<32> bs(x);
			for (int j = 0; j < 32; j++) {
				if (bs[j])
					tr[j].rangeFlip(l, r + 1);
			}

		}
	}
}

int main() {
	fastio;
	int _ = 1;
	while (_--) solve();

	return 0;
}