#include <bits/stdc++.h> 
using namespace std;

#define mod (114514)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

ll l, k; //日志，切了k题，x多少行
ll v[mod] {};

//x越大，那么需要写的代码越少，切题数量更多
ll f(ll x) {

	ll sum = 0;
	ll cnt = 0;
	for (int i = 0; i < l; i++) {
		if (sum + v[i] < 0) {
			sum = 0;
		} else
			sum += v[i];
		if (sum >= x) {
			cnt++;
			sum = 0;
		}
	}
	
	return cnt;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

   	cin >> l >> k;
   	ll mxx = -0x3f3f3f3f3f3f3f3f;
   	ll sub_mx = -0x3f3f3f3f3f3f3f3f;
   	for (int i = 0; i < l; i++) {
   		cin >> v[i];
   		sub_mx = max(v[i] + sub_mx, v[i]);
   		mxx = max(mxx, sub_mx);
   	}

   	ll lf = 1, r = mxx;
   	ll mid, ans_mx = -1;
   	ll op;
   	while (lf <= r) {
   		mid = (lf+r)>>1;
   		op = f(mid);
   		if (op >= k) {
   			lf = mid+1;
   			if (op == k)
	   			ans_mx = mid;
   		} else {
   			r = mid-1;
   		}
   	}

   	lf = 1; r = mxx;
   	ll ans_mi = -1;
   	while (lf <= r) {
   		mid = (lf+r)>>1;
   		op = f(mid);
   		if (op <= k) {
   			r = mid-1;
   			if (op == k)
	   			ans_mi = mid;
   		} else {
   			lf = mid+1;
   		}
   	}

   	if (ans_mi == -1 || ans_mx == -1)
   		cout << -1;
   	else 
 	  	cout << ans_mi << ' ' << ans_mx;
	return 0;
}