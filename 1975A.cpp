#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int v[mod];
map<int, int> d;

void solve() {
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}	

	// 7 2 2 3 9
	// 18 17 20 19    
	//d.clear();
	/*for (int i = 0; i < n; i++) {
		d[v[i]]++;
		if (d[v[i]] > 1) {
			if (v[i-1] != v[i]) {
				cout << "NO" << endl;
				return;
			}
		}
	}*/

	for (int i = 0; i < n; i++) {
		if (i != 0) {
			if (v[i-1] > v[i]) {
				if (i == n-1) {
					cout << "NO" << endl;
					return;
				}
				else if (v[i+1] != v[i]) {
					cout << "NO" << endl;
					return;
				}
			}
		}
	}

	cout << "YES" << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}