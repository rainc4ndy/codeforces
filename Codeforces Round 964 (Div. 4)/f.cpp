#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e9+7;
const int MAXN = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

ll v[MAXN], pa1[MAXN], pb1[MAXN], pa0[MAXN], pb0[MAXN];

void solve() {
	ll n, k;
	cin >> n >> k;

	for (int i = 1; i <= n;i++) {
		cin >> v[i];
	}

	pa1[0] = 0;
	pa0[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i] == 1) {
			pa1[i] = pa1[i-1] + 1;
		} 
		else {
			pa0[i] = pa0[i-1] + 1;
		}
	}

	pb1[n+1] = 0;
	pb0[n+1] = 0;
	for (int i = n; i >= 1; i--) {
		if (v[i] == 1) {
			pb1[i] = pb1[i+1] + 1;
		} else {
			pb0[i] = pb0[i+1] + 1;
		}
	}

	ll x, y;
	for (int i = 1; i <= n; i++) {
		x = pa1[i] + pb1[i];
		if (x > k) {
			
		}
		g = pa1[i] + pb1[i] - pa0[i] - pb0[i];
		if (g >= (k/2)+1) {
			//
		}
	}
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