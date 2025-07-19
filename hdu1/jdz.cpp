#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

ll pa[mod];

void solve() {
	ll n;
	cin >> n;
	ll x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		pa[i] = pa[i-1] + abs(x);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += pa[i];
	}
	cout << ans;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}