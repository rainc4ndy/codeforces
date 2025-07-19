#include <bits/stdc++.h> 
#include <cmath>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll n;
	cin >> n;	
	

	ll ans = 0;
	ans = ((n / 15) * 3);
	n %= 15;
	for (int i = 0; i < n+1; i++) {
		if (i % 3 == i % 5) {
			ans++;
		}
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