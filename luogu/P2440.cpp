#include <bits/stdc++.h> 
using namespace std;

#define mod (100001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

ll v[mod]{};
ll n, k;

bool check(ll x) {
	ll r = 0;
	for (int i = 1; i <= n; i++) {
		r += v[i] / x;
	}
	return r >= k;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	cin >> n >> k;

	ll mx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		mx = max(v[i], mx);
	}

	ll l = 0, r = mx, mid;
	ll ans = 0; 
	while(l<=r){
		mid=(l+r)>>1;
		if (!mid)
			break;
		if(check(mid)) l=(ans=mid)+1;//在右区间查找，同时更新答案
		else r=mid-1;//在左区间查找
	}

	cout << ans;

	return 0;
}