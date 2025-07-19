#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

const int mod = 2e6+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

ll um[mod] {};
ll f(ll n) {
	if (um[n])
		return um[n];
	ll bk = n;
    ll count = 0;
    while (n > 0) {
        n /= 3;
        count++;
    }
    return um[bk] = count;
}

void solve() {

	ll l, r;
	cin >> l >> r;

	ll ans = f(l)*2 + f(l+1);
	for (ll i = l+2; i <= r; i++) {
		ans += f(i);
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