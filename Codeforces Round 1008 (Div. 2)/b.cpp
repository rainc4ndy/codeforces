#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll n,k;
	cin >> n >> k;

	if (n == 1) {
		cout << n << endl;
		return;
	}

	if (k & 1) {
		for (int i = 0; i < n-1;i++) {
			cout << n << ' ';
		}
		cout << n-1 << endl;
	} else {
		for (int i = 0; i < n-2;i++) {
			cout << n-1 << ' ';
		}
		cout << n << ' ' << n - 1 << endl;
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