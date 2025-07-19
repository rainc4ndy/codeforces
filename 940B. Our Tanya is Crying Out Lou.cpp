#include <bits/stdc++.h> 
using namespace std;

#define mod (100001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	
    ll n, k, a, b;
    cin >> n >> k >> a >> b;

    ll ans = 0;
    while (n != 1) {
    	if (n % k == 0) {
    		if ((n - n/k) * a <= b) {
    			ans += (n-1)*a;
    			n = 1;
    		} else {
    			ans += b;
    			n /= k;
    		}
    	} else {
    		ans += (n % k) * a; //--;
    		n -= n % k;

    		if (!n) {
    			n = 1;
    			ans -= a;
    		}
    	}
    }

    cout << ans;
	return 0;
}