#include <bits/stdc++.h>
#include <random>
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
const int maxn = 4e5 + 10;
const ll mod = 998244353;
const ll base = 131313131;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    
    vector<ll> pw(n+1), h(n);
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i-1] * base % mod;
    }
    h[0] = (s[0] - 'a' + 1) % mod;
    for (int i = 1; i < n; i++) {
        h[i] = (h[i-1] * base + (s[i] - 'a' + 1)) % mod;
    }

    auto get_hash = [&](int l, int r) -> ll {
        ll res = h[r];
        if (l > 0) {
            res = (res - h[l-1] * pw[r-l+1] % mod + mod) % mod;
        }
        return res;
    };
    for (int len = n/2 + 1; len < n; len++) {
        if (get_hash(0, len-1) == get_hash(n-len, n-1)) {
            cout << "YES\n" << s.substr(0, len) << "\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
	fastio;
	solve();

	return 0;
}