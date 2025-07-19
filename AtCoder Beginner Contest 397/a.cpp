#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	double n; 
	cin >> n;
	if (n >= 38.0) {
		cout << 1;
	} else if (n >= 37.5 && n < 38) {
		cout << 2;
	} else {
		cout << 3;
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}