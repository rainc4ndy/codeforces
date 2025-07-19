#include <bits/stdc++.h> 
using namespace std;

#define mod (50001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int v[mod] {};
ll len, n, m;

bool check(ll ans) {
	ll cnt = 0;
	ll last = 0;
	for (int i = 0; i <= n; i++) {
		if (v[i] - last < ans) {
			cnt++;
		} else {
			//不用移，更新现在站的
			last = v[i];
		}
	}

	if (cnt <= m)
		return true;
	return false;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 


    cin >> len >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}	
	v[n] = len;

	ll l = 1, r = len;
	ll mid, ans;
	while (l <= r) {
		mid = (l+r)>>1;
		if (check(mid)) {
			l = (ans=mid)+1;
		} else {
			r = mid-1;
		}
	}
	cout << ans;

	return 0;
}