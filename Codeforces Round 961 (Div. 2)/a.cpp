#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n,k;
	cin >> n >> k;

	if (k == 0) {
		cout << 0 << endl;
		return;
	}
	if (k <= n) {
		cout << 1 << endl;
		return;
	} else {
		int ans = 1;
		k -= n;

		for (int i = n-1; i >= 1; i--) {
			if (k > 0) {
				k -= i;
				ans++;

				if (k > 0) {
					k -= i;
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t ;
	cin >> t;
	while (t--) solve();	

	return 0;
}