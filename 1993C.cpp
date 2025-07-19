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
	ll n, k;

	ll c[k*8];

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		int t = v[i] % 2*k;
		int status = 1;
		while (t < k*8) {
			if (status) c[t]++;
			else c[t]--;
			status ^= 1;
		}
		t += k;
	}

	int cnt = 0;
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