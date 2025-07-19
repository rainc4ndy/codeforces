#include <bits/stdc++.h>
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

struct trie {
	int nex[100000][26], cnt;
	bool exist[100000];  // 该结点结尾的字符串是否存在
	void insert(char *s, int l) {  // 插入字符串
		int p = 0;
		for (int i = 0; i < l; i++) {
			int c = s[i] - 'a';
			if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
			p = nex[p][c];
		}
		exist[p] = true;
	}
	bool find(char *s, int l) {  // 查找字符串
		int p = 0;
		for (int i = 0; i < l; i++) {
			int c = s[i] - 'a';
			if (!nex[p][c]) return 0;
			p = nex[p][c];
		}
		return exist[p];
	}
};

void solve() {

}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}