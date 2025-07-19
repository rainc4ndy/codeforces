#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	string s;
	cin >> s;
	if (s.size() >= 2) {
		if (s[0] == '1' && s[1] == '0') {
			if (s.size() >= 3) {
				if (s.size() == 3 && s[2] == '1') {
					cout << "NO" << endl;
					return;
				} 
				if (s[2] == '0') {
					cout << "NO" << endl;
					return;
				}
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		} else {
			cout << "NO" << endl;
		}
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