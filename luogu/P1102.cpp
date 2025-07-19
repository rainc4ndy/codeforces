#include <algorithm>
#include <bits/stdc++.h> 
using namespace std;

#define ll long long 

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	ll n, c;

	cin >> n >> c;

	vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += ((upper_bound(v.begin(), v.end(), v[i]-c)-v.begin()) - (lower_bound(v.begin(), v.end(), v[i]-c)-v.begin()));
	}	

	cout << ans;


	return 0;
}