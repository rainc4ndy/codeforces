#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {	
	int n;
	string d;
	cin >> n >> d;

	vector<string> v(n);
	for (int i =0 ; i < n; i++) {
		cin >> v[i];
	}

	for (int i =0 ; i < n; i++) { 
		if (v[i] == d) {
			cout << i + 1 << endl;
			return;
		}
	} 
	cout << -1 << endl;
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