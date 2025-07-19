#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
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
const int maxn = 1e5 + 10;
const ll mod = 998244353;
const ll base = 131313131;

void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    // 模板串 A 和 B
    string A(n, '0'), B(n, '0');
    ll ha = 0, hb = 0;
    bool flag = 0;
    for (int i = 0; i < n; i += k) {
        for (int j = 0; j < k; j++) {
            A[i+j] = char('0' + flag);
            B[i+j] = char('0' + (flag ^ 1));
        }
        flag ^= 1;
    }
    string rs = s;
    reverse(rs.begin(), rs.end());

    vector<ll> pw(n+1, 1);
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i-1] * base % mod;
    }
    vector<ll> hs(n+1, 0), hrs(n+1, 0);
    for (int i = 0; i < n; i++) {
        hs[i+1]  = (hs[i]  * base + (s[i]  - '0' + 1)) % mod;
        hrs[i+1] = (hrs[i] * base + (rs[i] - '0' + 1)) % mod;
        ha = (ha * base + (A[i] - '0' + 1)) % mod;
        hb = (hb * base + (B[i] - '0' + 1)) % mod;
    }
    auto get_hs = [&](int l, int r) {
        ll x = (hs[r] - hs[l] * pw[r - l] % mod) % mod;
        return x < 0 ? x + mod : x;
    };
    auto get_hrs = [&](int l, int r) {
        ll x = (hrs[r] - hrs[l] * pw[r - l] % mod) % mod;
        return x < 0 ? x + mod : x;
    };

    //    new_s = s[p..n-1] + reverse(s[0..p-1])
    //    哈希 = hash(s[p..]) * base^p + hash(reverse(s[0..p-1]))
    for (int p = 1; p <= n; p++) {
        // 后缀部分 s[p..n-1] → hs 的区间 [p+1, n+1)
        ll h_suf = (p < n ? get_hs(p, n) : 0);
        // 前缀反转部分 reverse(s[0..p-1]) 恰好是 rs[n-p .. n-1]
        // rs 索引 0-based → 区间 [n-p, n)
        ll h_revpre = get_hrs(n-p, n);
        // 拼接
        ll h_new = (h_suf * pw[p] + h_revpre) % mod;

        if (h_new == ha || h_new == hb) {
            cout << p << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}


int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}