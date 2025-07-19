#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n; string s;
	cin >> n;
	cin >> s;

	if (s[0] == 'a') {
		for (auto& it : s) {
			char c =(char)((it + 1) % ('z'+1)); 
			c = c < 'a' ? c +'a' :c;
			cout << c;
		}
		cout << endl;
	} else {
		
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