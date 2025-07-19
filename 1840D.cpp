#include <algorithm>
#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

ll v[mod];
ll n;

bool check(ll x) {
	int cur = 0;
    for (int i = 0; i < 3; ++i) {
        int start = v[cur];
        int end = start + 2 * x;
        while (cur < n && v[cur] <= end) {
            ++cur;
        }
        if (cur >= n) {
            return true;
        }
    }
    
    return cur >= n;
}

void solve() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}	
	
	sort(v, v+n);

	ll l = 0, r = 1e9;
	ll mid,ans=1e9;
	//mid为三者雕刻所需要的最大时间
	//check的时候，尽可能多的在mid时间内为雕刻师安排多的v
	//显然这个问题具有单调性，如果用时越久，模具的制作偏差就越大
	while (l <= r) {
		mid=(l+r)>>1;
		if (check(mid)) {
			r = mid-1;
			ans = mid;
		} else {
			l = mid+1;
		}
	}
	cout << ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}