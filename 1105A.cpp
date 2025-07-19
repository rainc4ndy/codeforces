#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n; cin >> n;
	vector<int> v(n); 
	for (int i =0 ; i< n;i++ ) cin >> v[i];

	int ans = 1, mx = 0x3f3f3f3f;
	for (int t = 1; t <= 100; t++) {
		int cur = 0;
		for (int i =0 ; i< n;i++) {
			if (abs(t - v[i]) > 1) cur += abs(t - v[i]) - 1;
		} 
		if (cur < mx) {
			mx = cur;
			ans = t;
		}
	}


	cout << ans << ' ' << mx;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}