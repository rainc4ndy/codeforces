#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll n; 
	cin >> n;

	if (n & 1) {
		if (n < 27) {
			cout << -1 << endl;
		} else {
			int x = 3;
			map<int, int> mp;
			for (int i = 1; i <= n; i++) {
				if (i == 1 || i == 10 || i == 26) {
					cout << 1 << ' ';
				}
				else if (i == 27 || i == 23) cout << 2 << ' ';
				else {
					cout << x << ' ';
					mp[x]++;
					if (mp[x] == 2) x++;
				}
			}
		}
		return;
	} else {
		for (int i = 1; i <= n/2;i++) {
			cout << i << ' ' << i << ' ';
		}
		cout << endl;
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