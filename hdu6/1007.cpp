#include <algorithm>
#include <bits/stdc++.h> 
#include <functional>
#include <iterator>
#include <numeric>
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
	ll n;
	cin >> n;

	vector<ll> r, b;

	vector<ll> v(n);

	for (ll i = 0; i < n; i++) {
		cin >> v[i];
	}

	char c;
	for (ll i = 0; i < n; i++) {
		cin >> c;
		if (c == 'R') {
			r.emplace_back(v[i]);
		} else b.emplace_back(v[i]);
	}

	sort(begin(r), end(r), std::greater<ll>()), sort(begin(b), end(b), std::greater<ll>());

	ll ans = 0;
	if (r.size() > b.size()) {
		for (ll i = 0; i < b.size(); i++) ans += b[i];
		for (ll i = 0; i < b.size()+1; i++) ans += r[i];
	} else if (r.size() == b.size()) {
		for (ll i = 0; i < b.size(); i++) ans += b[i];
		for (ll i = 0; i < b.size(); i++) ans += r[i];
	} else {
		for (ll i = 0; i < r.size(); i++) ans += b[i];
		for (ll i = 0; i < r.size(); i++) ans += r[i];
	}
	cout << ans << endl;
}	


int main() {    
    fastio;
	int _;
	cin >> _;
	while(_--) solve();

	return 0;
}