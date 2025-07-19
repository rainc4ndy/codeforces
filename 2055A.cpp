#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n,a,b;
	cin >> n >> a >> b;
	if (n == 2) {
		cout << "NO" << endl;
		return;
	}
	if ((abs(a-b)-1) % 2 == 0) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
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