#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

ll v[mod];

void solve() {
	int n;
	cin >> n;
	for (int i =0;i<n;i++) {
		cin >> v[i];
	}

	ll ans = v[n-1];
	ll r = v[n-2];
	for (int i =0;i < n-2;i++) {
		r -= v[i];
	}
	cout << ans - r << endl;
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