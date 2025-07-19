#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll m,a,b,c;
	cin >> m >> a >> b >> c;

	ll x = min(m, a), y = min(m, b);
	ll r = m - x + m - y;

	ll ans = x + y;
	if (r) {
		ans += min(r, c);
	}

	cout << ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _;
	cin >> _;
	while(_--) solve();

	return 0;
}