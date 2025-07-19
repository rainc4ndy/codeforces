#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int a, b;
	cin >> a >> b;

	if (!a && (b&1)) {
		cout << "NO" << endl;
		return;
	}

	if (!b && (a&1)) {
		cout << "NO" << endl;
		return;
	}

	if (a&1) {
		cout << "NO" << endl;
	} else if ((a+2*b)%2==0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
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