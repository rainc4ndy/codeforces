#include <bits/stdc++.h> 
#include <iterator>
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

	set<string> um;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		sort(begin(s), end(s));
		um.insert(s);
	}
	cout << um.size();
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}