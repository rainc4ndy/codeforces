#include <algorithm>
#include <bits/stdc++.h> 
#include <functional>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll n,k;
	cin >> n >> k;

	vector<ll> v(n);
	for (int i =0; i < n; i++) {
		cin >> v[i];
	}

	if (k == 1) {
		ll ans = v[0] + v[n-1];
		for (int i = 1; i < n-1; i++) {
			ans = max(ans, v[i] + max(v[0], v[n-1]));
		} 
		cout << ans << endl;
	} else {
		if (k >= n) {
			cout << accumulate(begin(v), end(v), 0) << endl; 
			return;
		}
		sort(begin(v), end(v), greater<ll>());

		ll ans = 0;
		int i = 0;
		for (i = 0; i < k+1; i++) {
			ans += v[i];
		}	
		cout << ans << endl;
	}

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