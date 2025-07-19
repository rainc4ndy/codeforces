#include <algorithm>
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

	reverse(begin(s), end(s));

	for (auto it :s) {
		if (it == 'p') cout << 'q';
		else if (it == 'q') cout << 'p';
		else cout << it;
	}
	cout << endl;
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