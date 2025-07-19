#include <bits/stdc++.h> 
#include <vector>
using namespace std;


#define ll long long
const ll mod = 1e9+7;

ll v[200001];
int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    ll t;
    cin >> t;
    ll n, k;

    std::vector<ll> ans(t);

    for (int i = 0; i < t; i++) {
    	cin >> n >> k;

    	for (int j = 1; j <= n; j++) {
            cin >> v[j];
    	}
        ll cur_sum = 0;
        ll mx = 0;
        ll sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += v[j];
            cur_sum = max(cur_sum + v[j], v[j]);
            mx = max(mx, cur_sum);
        }

        sum %= mod;
        while (k--) {
            sum = (sum + mx) % mod;
            mx = mx * 2 % mod;
        }
        sum = sum % mod + mod;
        sum %= mod;
        ans[i] = sum;
    }

    for (int i = 0; i < t; i++) {
        cout << ans[i];
        if (i != t-1)
            cout << endl;
    }

	return 0;
}