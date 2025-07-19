#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

ll n, k;
ll v[mod];

bool check(ll h) {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i] / h;
	}
	return sum >= k;
}

void solve() {
	cin >> n >> k;
	ll mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mx = max(v[i], mx);
	}

	ll l = 1, r = mx, mid, ans = -1;
	while (l <= r) {
		mid = (l+r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid+1;
		} else {
			r = mid-1;
		}
	}
	cout << ans;
} 

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	solve();

	return 0;
}