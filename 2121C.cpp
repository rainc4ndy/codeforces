#include <bits/stdc++.h>
#include <cwchar>
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
    for (auto &i: a) read(i);
}
template<class T>
void read(T &a) {
    cin >> a;
}
#define TIME cout<<(double)clock()/CLOCKS_PER_SEC <<"ms"<<endl;
#define debug(x) cout << #x << ' ' << x << endl;
const int maxn = 2e5 + 10;
const ll mod = 998244353;

void solve() {
	int n,m;
	cin >> n >> m ;
	vector<vector<int>> g(n, vector<int>(m));
	for (int i = 0;i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
		}
	}

	vector<int> mxr(n); vector<int> mxc(m);
	vector<int> mxr_c(n); vector<int> mxc_c(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] > mxr[i]) {
				mxr[i] = g[i][j];
				mxr_c[i] = 1;
			} else if (g[i][j] == mxr[i]) {
				mxr_c[i]++;
			}
			if (g[i][j] > mxc[j]) {
				mxc[j] = g[i][j];
				mxc_c[j] = 1;
			} else if (g[i][j] == mxc[j]) {
				mxc_c[j]++;
			}		
		}
	}
	pii res; pii p;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int mx = 0, cnt = 0;
			if (mxr[i] > mxc[j]) {
				mx = mxr[i], cnt = mxr_c[i];
			} else if (mxr[i] < mxc[j]){
				mx = mxc[j], cnt = mxc_c[j];
			} else {
				int alpha = (mxr[i] == g[i][j] || mxc[j] == g[i][j]);
				mx = mxr[i], cnt = mxr_c[i] + mxc_c[j] - alpha;
			}
			if (mx > res.x || (mx == res.x && cnt > res.y)) {
				res = {mx, cnt};
				p = {i, j};
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == p.x || j == p.y) {
				ans = max(ans, g[i][j]-1);
			} else {
				ans = max(ans, g[i][j]);
			}
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