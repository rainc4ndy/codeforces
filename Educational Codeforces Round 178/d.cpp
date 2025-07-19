#include <bits/stdc++.h>
#include <numeric>
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
const ll maxn = 6e6+10;
const ll mod = 998244353;

vb ok(maxn, true);
vl ele(maxn);
vl pa(maxn);

void work() {
    for (ll i = 2; i <= maxn / i; i++) {
        if (ok[i]) {
            for (ll j = i * i; j <= maxn; j += i) {
                ok[j] = false;
            }
        }
    }
    ok[0] = false;
    ok[1] = false;
    for (ll i = 0; i < maxn; i++) {
        if (ok[i]) {
            ele[i] = i;
        }
    }
    sort_all(ele);
    unq_all(ele);
    pa[0] = 0;
    for (int i = 1; i < (int)ele.size(); i++) {
        pa[i] = pa[i - 1] + ele[i];
    }
}

void solve() {
    nin;
    vl v(n);
    read(v);
    sort_all(v);
    ll sum = accumulate(all(v), 0LL);
    for (int i = 0; i < n; i++) {
        int now = n - i;
        if (pa[now] <= sum) {
            cout << i << "\n";
            return;
        } else {
            sum -= v[i];
        }
    }
    cout << n - 1 << "\n";
}

int main() {
    fastio;
    work();
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}
