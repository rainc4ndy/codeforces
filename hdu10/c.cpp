#include <algorithm>
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


struct Sieve {
    vector<bool> isp;
    vector<int> primes;
    int top;
    // 欧拉筛 筛出top范围内的所有的质数
    Sieve(int top_ = 300300) {
        top = top_ + 1;
        isp.assign(top, true);
        isp[1] = false;
        for (int i = 2; i < top; ++i) {
            if (isp[i]) {
                primes.push_back(i);
            }
            // Euler sieve method O(n).
            for (int p : primes) {
                int x = i * p;
                if (x >= top) break;
                isp[x] = false;
                if (i % p == 0) break;
            }
        }
    }
    // 分解质因数 并统计改质因数的数量
    map<int, int> factorization(int v) {
        map<int, int> res;
        for (int p : primes) {
            if (v == 1) break;
            if (ll(p) * p > v) break;
            int cnt = 0;
            while (v % p == 0) {
                cnt++;
                v /= p;
            }
            if (cnt) {
                res[p] = cnt;
            }
        }
        if (v > 1) res[v] = 1; // final large prime.
        return res;
    }
    // 求所有的约数
    vector<int> divisors(int v) {
        map<int, int> f = factorization(v);
        vector<int> res;
        res.push_back(1);
        for (auto [p, c] : f) {
            int t = res.size(), x = 1;
            for (int i = 0; i < c; ++i) {
                x *= p;
                for (int j = 0; j < t; ++j) {
                    res.push_back(res[j] * x);
                }
            }
        }
        return res;
    }
    bool isPrime(int v) {
        if (v < top) return isp[v];
        assert(ll(top - 1) * (top - 1) >= v);
        for (int p : primes)
            if (v % p == 0)
                return false;
        return true;
    }
};

const ll N = sqrt(2e9) + 10;
Sieve sieve(N);

void solve() {
	nin;
	vector<pll> v(n);read(v);
	int lim = max(
		lower_bound(all(sieve.primes), v[0].x) - begin(sieve.primes),
		lower_bound(all(sieve.primes), v[0].y) - begin(sieve.primes)
		);
	for (int i = 0; i <= lim; i++) {
		ll p = sieve.primes[i];
		bool ok = true;
		for (int j = 1; j < n; j++) {
			if (v[j].x % p == 0 || v[j].y % p == 0) {
				//ok
			} else {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << p << endl;
			return;
		}
	} 
	cout << -1 << endl;
}

int main() {
	fastio;
	int _ = 1;
	//cin >> _;
	while (_--) solve();

	return 0;
}