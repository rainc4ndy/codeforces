#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n,k,p;
	cin >> n >> k >> p;

	// i, x 
	// ai = x
	// sum to k;
	k = abs(k);
	if (n*p < k) {
		cout << -1 << endl;
		return;
	} else {
		if ( k % p == 0) {
			cout << k / p << endl;
		} else {
			cout << (k / p) + 1 << endl;
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