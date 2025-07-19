#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll n,t;
	cin >> n >> t;

	vector<int> v(n);
	for (int i =0;i <n; i++) cin >> v[i];

	auto check = [&](int x) {
		int l = 0, r = 0, sum = 0, mx = 0;
		for (int r = 0; r < n; r++) {
			sum += v[r];
			while (sum > t && l <= r) sum -= v[l++];
			mx = max(mx, r-l+1);
		}
		return mx >= x;
	};

	int l = 0, r = 0x3f3f3f3f,mid,ans;
	while (l<=r) {
		mid =(l+r) >>1;
		if (check(mid)) {
			l = mid+1;
			ans = mid;
		}	
		else r = mid-1;
	}

	cout << ans;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ =1;
	while(_--) solve();

	return 0;
}