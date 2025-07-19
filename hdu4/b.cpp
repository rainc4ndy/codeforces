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
	map<int,int> m;

	for (int i =0; i <7;i++) {
		int x;
		cin >> x;
		m[x]++;
	}

	bool b1 = false, b2 = false;
	for (auto it : m) {
		if (it.y >= 3 && !b2) {
			b2 = true;
		}
		else if (it.y >= 2) {
			b1 = true;
		}
	
	}

	if (b1 && b2) Yes;
	else No;
}

int main() {    
    fastio;

	int _ = 1;
	while(_--) solve();

	return 0;
}