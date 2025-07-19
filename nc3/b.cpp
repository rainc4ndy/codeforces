#include <bits/stdc++.h> 
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> v(101);
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll goa(const std::vector<ll>& numbers) {
    ll n = numbers.size();
    if (n == 0) return 0;
    ll result = numbers[0];
    for (ll i = 1; i < n; ++i) {
        result = gcd(result, numbers[i]);
        if (result == 1) {
            return 1;
        }
    }
    return result;
}

signed main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	ll n, d;
	cin >> n >> d;

	for (ll i = 0; i < n; i++) {
		cin >> v[i];
	}

	ll g = goa(v);
	cout << "g =" << g << endl;
	
	cout << d % g;
	return 0;
}