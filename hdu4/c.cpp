#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof (arr))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define import mt19937
#define random rnd(chrono::system_clock::now().time_since_epoch().count())
#define setdb(v) setprecision(v)
#define debug(x) cout << #x << ' ' << x << endl;
#define fi first
#define se second
#define x first
#define y second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
#define zfc(s) cout << #s << '\n'
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5+10;


void solve() {
	int n;
	cin >> n;

	vector<ll> v(n);
	for (int i = 0; i < n;i++) {
		cin >> v[i];
	}

	map<ll, ll> m;
	for (int i = 0; i < n; i++) {
		m[v[i]]++;
	}

	ll mx = -1;
	for (auto it : m) {
		if (it.y == 1) {
			mx = max(mx, it.x);
		}
	}
	if (mx == -1) {
		cout << -1;
	} else {
		for (int i = 0; i < n; i++) {
			if (v[i] == mx) {
				cout << i+1;
				return;
			}
		}
	}
}

int main() {    
    fastio;

	int _ = 1;
	while(_--) solve();

	return 0;
}