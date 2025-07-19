#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;



void solve() {
	ull x;

	cin >> x;

	ull lb;
	lb = x >= 3 ? x/3 : x;

	for (ull i = x-lb; i <= x; i++) {
		if (__gcd(i, x) == (i ^ x)) {
			cout << i << endl;
			return;
		}
	}
	cout << -1;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}