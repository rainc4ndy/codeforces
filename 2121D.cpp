#include <bits/stdc++.h>
#include <utility>
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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	vector<pii> l(2*n+1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	vector<pii> ans;
	auto mov = [&](int t, int x) {
		ans.eb(t, x + 1); //1 based
		if (t == 1) {
			swap(a[x], a[x + 1]);
		} else if (t == 2) {
			swap(b[x], b[x + 1]);
		} else {
			swap(a[x], b[x]);
		}

		// cout << "---------------------\n";
		// for (int i = 0; i < n; i++) {
		// 	cout << a[i] << ' ';
		// }
		// cout << '\n';
		// for (int i = 0; i < n; i++) {
		// 	cout << b[i] << ' ';
		// }
		// cout << '\n';
	};

	//odd a
	for (int i = 0, j = 1; i < n; i++, j += 2) {
		l[j] = {false, i};
	}
	//even b
	for (int i = 0, j = 2; i < n; i++, j += 2) {
		l[j] = {true, i};
	}

	for (int i = 1; i <= 2*n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j] == i) {
				if (l[i].x == false) {
					int lim = abs(j - l[i].y);
					for (int k = 1; k <= lim; k++) {
						mov(1, j - k);
					}
				} else {
					mov(3, j);
					int lim = abs(j - l[i].y);
					for (int k = 1; k <= lim; k++) {
						mov(2, j - k);
					}
				}
				break;
			}
		}
		for (int j = 0; j < n; j++) {
			if (b[j] == i) {
				if (l[i].x == true) {
					int lim = abs(j - l[i].y);
					for (int k = 1; k <= lim; k++) {
						mov(2, j - k);
					}
				} else {
					mov(3, j);
					int lim = abs(j - l[i].y);
					for (int k = 1; k <= lim; k++) {
						mov(1, j - k);
					}
				}
				break;
			}
		}
	}

	cout << ans.size() << '\n';
	for (auto it : ans) {
		cout << it.x << ' ' << it.y << '\n';
	}
}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}