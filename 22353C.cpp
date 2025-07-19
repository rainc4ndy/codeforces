#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

ll v[mod]{};
ll L,n,m;

bool check(ll x) {
	ll last = 0;
	ll r = 0;
	for (int i = 1; i <= n+1; i++) {
		if (v[i] - v[last] < x) {
			r++;
		}
		else last = i;
	}
	if (r <= m)
		return true;
	return false;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL); 

    cin >> L >> n >> m;
    for (int i = 1; i <= n; i++) {
    	cin >> v[i];
    }
    v[n+1] = L;

    ll l = 0, r = L;
    ll mid;
    ll ans = 0;
    while (l <= r) {
    	mid = (l+r)>>1;
    	if (check(mid)) {
    		ans = mid;
    		l = mid+1;
    	} else {
    		r = mid-1;
    	}
    }
    cout << ans;

	return 0;
}