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
	
	int a = 0,b = 0,c =0 ,d=0;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "Au")
			a++;
		if (s == "Ag")
			b++;
		if (s == "Cu")
			c++;
		if (s == "Fe")
			d++;
	}
	cout << a + min(b,c) << endl;
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