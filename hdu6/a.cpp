#include <algorithm>
#include <bits/stdc++.h> 
#include <vector>
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
    ll k;
    cin >> k;

    vector<ll> v(3);
    for (int i = 0; i < 3; i++) cin >> v[i];

    ll best = 0;
    for (int i = 0; i < 8; ++i) {
        ll sum = 0;
        for (int j = 0; j < 3; ++j) {
            if (i & (1 << j)) sum += v[j];
        }
        if (sum <= k) {
            best = max(best, sum);
        }
    }

    cout << (k - best) << '\n';
}


int main() {    
    fastio;
	int _;
	cin >> _;
	while(_--) solve();

	return 0;
}