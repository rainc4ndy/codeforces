#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

ll v[mod], d[mod];
ll n, k;

bool check(ll x) {
	ll cnt = 0;
	ll r = k;

	for (int i = 0; i < n; i++) {
		d[i] = v[i];
	}

	//每次从数组的全部元素中减去一个最小值
	//如果某个元素在过程中变成了0，尽可能用k去补填

	ll i = 0;
	while (r > 0) {
		ll val = d[i];
		bool ok = true;
		for (int j = 0; j < n; j++) {
			if (!d[j]) {
				if (r > 0) {
					d[j] += val;
					r -= val;
				} else {
					ok = false;
				}
			}
			d[j] -= val;
		}
		if (!ok) {
			break;
		}
		cnt += val;
		i++;
	}

	if (cnt > 1) {
		cnt += cnt-1;
	}
	cout << "cnt = " << cnt << endl;
	return cnt >= x;
}

void solve() {
	cin >> n >> k;	
	ll mi = 0x3f3f3f3f;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mi = min(mi,v[i]);
	}

	ll ans = 0;
	
	for (int i = 0; i < n; i++) {
		sort(v, v+n);
		for (int j = 0; j < n; j++) {

		}
	}

	/*ll l = mi,r = 0x3f3f3f3f;
	ll ans = 0,mid;
	while(l<=r) {
		mid=(l+r)>>1;
		if (check(mid)) l = (ans=mid)+1;
		else r=mid-1;
	}*/
	cout << ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin>>t;
	while(t--)solve();



	return 0;
}