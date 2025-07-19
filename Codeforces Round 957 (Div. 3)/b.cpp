#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

ll v[mod];

void solve() {
	ll n, k;
	cin >> n >> k;

	ll mx = 0, mxi = 0;
	for (int i = 0; i <k;i++) {
		cin >> v[i];
		if (v[i] > mx) {
			mx = v[i];
			mxi = i;
		}
	}

	int ans = 0;
	for (int i = 0; i < k; i++) {
		if (i != mxi) {
			ans += v[i]+(v[i]-1);
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
	while (t--)
		solve();

	return 0;
}