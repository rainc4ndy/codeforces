#include <bits/stdc++.h> 
using namespace std;

#define mod (100001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int d[33] {};

void solve() {
	ll l, r;
	cin >> l >> r;

	//ll x = r;
	for (int i = 32; i > 0; i--) {
		if (l <= d[i] && d[i] <= r) {
			//x = d[i];
			cout << i << endl;
			break;
		}
	}
 	//cout << "x = " << x << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    d[0] = 1;
    for (int i = 1; i <= 32; i++) {
    	d[i] = d[i-1] * 2;
    }

    int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}