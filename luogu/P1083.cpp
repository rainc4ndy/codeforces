#include <bits/stdc++.h> 
using namespace std;

#define mod (1000001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

ll n, m;
ll lim[mod] {};
ll ca[mod] {};

ll diff[mod] {}; //差分
ll vd[mod], vs[mod], vt[mod]; //d个，s天到t天

//查找x，看看教室在x这里会不会被借完
//不难发现答案具有单调性
bool ck(int x) {
	//从第一位开始借，一直到x
	diff[0] = lim[0];
	for (int i = 1 ;i <= n; i++) {
   		diff[i] = lim[i] - lim[i-1];
   	}

   	//施加影响
	for (int i = 1; i <= x; i++) {
 		diff[vs[i]] -= vd[i];
 		diff[vt[i]+1] += vd[i];
   	}

   	memcpy(ca, lim, sizeof(lim));

   	//恢复原数组
   	ca[0] = diff[0];
   	for (int i = 1; i <= n; i++) {
   		ca[i] = ca[i-1] + diff[i];
   		if (ca[i] < 0) {
   			return false;
   		}
   	}
   	return true;
}
int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

   	cin >> n >> m;

   	for (int i = 1 ;i <= n; i++) {
   		cin >> lim[i];
   	}

   	for (int i = 1; i <= m; i++) {
 		cin >> vd[i] >> vs[i] >> vt[i];
   	}

   	ll l = 1, r = m;
   	ll mid, ans = 0;
   	while (l <= r) {
   		mid = (l+r)>>1;
   		if (ck(mid)) {
   			//可以借完，那么扩大区间，寻找更优
   			l = mid+1;
   		} else {
   			r = mid-1;
   			ans = mid;
   		}
   	}

   	if (!ans) {
   		cout << 0;
   	} else {
   		cout << -1 << endl << ans;
   	}
 	return 0;
}