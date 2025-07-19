#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

int v[mod] {};
bool f[mod] {};
void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <=n;i++) {
		cin >> v[i];
		f[v[i]] = false;
	}

	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			f[v[i]] = true;
			continue;
		}
		if (v[i] == 1) {
			if (f[v[i]+1] == false) {
				cout << "NO" << endl;
				return;
			}
			f[v[i]] = true;
		} 
		else if (v[i] == n) {
			if (f[v[i]-1] == false) {
				cout << "NO" << endl;
				return;
			}
			f[v[i]] = true;
		} else {
			if (f[v[i]+1] == false && f[v[i]-1] == false) {
				cout << "NO" << endl;
				return;
			}
			f[v[i]] = true;
		}
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