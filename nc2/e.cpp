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
	if (x <= 2001) lb = 1;
	else lb = x - 2000;

	ull mx = 0;
	ull rec = 0;
	for (ull d = 3000; d <= 6000; d++) {
		x = d;
		for (ull i = lb; i <= x; i++) {
		if (__gcd(i, x) == (i ^ x)) {
				if (x-i > mx) {
					mx = x-i;
					rec = x;
				}
				cout << "x, y = " << x <<',' << i << endl;
			
		}
		}
	}
	cout << "mx = " << mx << endl;
	cout << "rec = " << rec << endl;
	
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