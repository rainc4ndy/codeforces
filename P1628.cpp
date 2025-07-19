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
	cin >> n;
	vector<string> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	string p;
	cin >> p;
	
	sort(begin(v),end(v));
	for (auto& it : v) {
		if (it.size() >= p.size()) {
			if (it.substr(0,p.size()) == p) {
				cout << it << endl;
			}
		}	
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}