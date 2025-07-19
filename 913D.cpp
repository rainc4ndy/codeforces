#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<ll, ll> P;

void solve() {
	int n;
	cin >> n;
	vector<P> v(n);
	for (int i =0;i < n;i++) {
		cin >> v[i].x >> v[i].y;
	}	

	auto check = [&](ll x) -> bool {
		int cur = 0;
		for (int i = 0; i < n; i++) {
			if (cur + x < v[i].x) {
				return false;
			}

			cur = min(v[i].y, cur+x);
		}
		return true;
	};

	ll l = 1, r  = 1e9, mid, ans = 0;
	while (l <= r) {
		mid = (l+r) >> 1;
		if (check(mid)) {
			r = mid-1;
			ans = mid;
		} else {
			l = mid+1;
		}
	}
	cout << "ans = " << ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _;
	cin >> _;
	while(_--) solve();

	return 0;
}