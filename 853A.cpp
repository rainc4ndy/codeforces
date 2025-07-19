#include <bits/stdc++.h> 
#include <cstdlib>
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
	ll n,k;
	cin>> n >> k;
	vector<pll> v(n);
	vector<ll> v2(n);
	set<ll> s;
	for (int i =0; i < n; i++) {
		cin >> v[i].x;
		v2[i] = v[i].x;
		v[i].y = i + 1;
		s.insert(i + 1 + k);
	}

	sort(begin(v), end(v), [&](pll&a, pll&b) {
		if (a.x == b.x)
			return a.y > b.y;
		return a.x > b.x;
	});

	ll ans = 0;
	vector<ll> t(n+1);
	for (int i = 0; i < n; i++) {
		if (v[i].y > k) {
			if (s.count(v[i].y)) {
				t[v[i].y] = v[i].y;
				s.erase(v[i].y);
			} else {
				t[v[i].y] = *s.begin();
				s.erase(s.begin());
			}
		} else {
			t[v[i].y] = *s.begin();
			s.erase(s.begin());
		}
	} 
	for (int i = 1; i <= n; i++) {
		ans += abs(i - t[i]) * v2[i-1];
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++) {
		cout << t[i] << ' ';
	}
}

int main() {    
    fastio;
	int _ = 1;
	while(_--) solve();

	return 0;
}