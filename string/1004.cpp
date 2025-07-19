#include <bits/stdc++.h>
#include <functional>
#include <queue>
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

struct SuffixAutomaton {
	struct Node {
		int next[26];
		int link, len;
		Node(): link(-1), len(0) {
			fill(next, next + 26, -1);
		}
	};
	vector<Node> st;
	int last;
	SuffixAutomaton(int maxlen = 0) {
		st.reserve(2 * maxlen);
		st.push_back(Node());
		last = 0;
	}
	int extend(char cc) {
		int c = cc - 'a';
		int cur = st.size();
		st.push_back(Node());
		st[cur].len = st[last].len + 1;

		int p = last;
		while (p != -1 && st[p].next[c] == -1) {
			st[p].next[c] = cur;
			p = st[p].link;
		}
		if (p == -1) {
			st[cur].link = 0;
		} else {
			int q = st[p].next[c];
			if (st[p].len + 1 == st[q].len) {
				st[cur].link = q;
			} else {
				int clone = st.size();
				st.push_back(st[q]);
				st[clone].len = st[p].len + 1;
				while (p != -1 && st[p].next[c] == q) {
					st[p].next[c] = clone;
					p = st[p].link;
				}
				st[q].link = st[cur].link = clone;
			}
		}
		last = cur;
		return st[cur].len - st[st[cur].link].len;
	}
};


void solve() {
	string s;
	cin >> s;
	int n = s.size();

	vector< vector<int> > ans(n + 2, vector<int>(n + 2, 0));

	for (int l = 1; l <= n; ++l) {
		SuffixAutomaton sa(n - l + 1);
		long long total = 0;
		for (int r = l; r <= n; ++r) {
			total += sa.extend(s[r - 1]);
			ans[l][r] = total;
		}
	}

	int Q;
	cin >> Q;
	while (Q--) {
		int l, r;
		cin >> l >> r;
		cout << ans[l][r] << "\n";
	}
}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}