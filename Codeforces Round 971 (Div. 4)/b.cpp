#include <algorithm>
#include <bits/stdc++.h> 
#include <iterator>
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n;
	cin >> n; 

	char c;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> c;
			if (c == '#') v.push_back(j+1);
		}	
	}
	reverse(begin(v), end(v));
	for (auto it : v) {
		cout << it << ' ';
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