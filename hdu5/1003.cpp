#include <bits/stdc++.h> 
#include <bitset>
using namespace std;

#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof (arr))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define random rnd(chrono::system_clock::now().time_since_epoch().count())
#define setdb(v) setprecision(v)
#define debug(x) cout << #x << ' ' << x << endl;
#define x first
#define y second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5+10;
const ll mod = 998244353;

void solve() {
	ull k,b,c,v;
	cin >> k >> b >> c >> v;
	ull dd = v - b^c;

	for (int x = 0; x < 10000; x++) {
		if (((k*x) ^ c) <= dd) {
			debug(k*x);
			debug(x);
			debug(bitset<31>(k*x).to_string());
			debug(bitset<31>(x).to_string());
			debug(bitset<31>(k).to_string());
			cout << "-----" << endl;
		}
	}
}

int main() {    
    fastio;
	int _;
	cin >> _;
	while(_--) solve();

	return 0;
}