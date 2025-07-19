#include <bits/stdc++.h> 
#include <cwchar>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll n,m,v,sum = 0;
	cin >> n >> m >> v;

	vector<ll> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		sum += d[i];
	}

	auto check = [&](ll x) -> bool {
		ll l = 0, r = 0, current_sum = d[0];
		while (r <= n) {
			if (current_sum >= x) {
				cout << "[l, r] = " << l << ' ' << r << endl;
				ll partial_sum = 0;
				ll cnt = 0;
				//check distribution
				for (int i = 0; i < n; i++) {
					if (i >= l && i <= r) 
						continue;
					partial_sum += d[i];
					if (partial_sum >= v) {
						partial_sum = 0;
						cnt++;
					}
				}

				if (cnt == m) {
					return true;
				}

				current_sum -= d[l];
				l++;
			} else {
				r++;
				current_sum += d[r];
			}
		}
		return false;
	};

	ll l = 0, r = sum, mid, ans = -1;
	while (l <= r) {
		mid = (l+r)>>1;
		cout << "mid = " << mid << endl;
		if (check(mid)) {
			l = mid+1;
			ans = mid;
		} else {
			r = mid-1;
		}		
	}
	cout << ans << endl;
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