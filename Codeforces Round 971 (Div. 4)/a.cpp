#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int a, b;
	cin >> a >> b;

	int ans = 0x3f3f3f3f;
	for (int c = a; c <= b; c++) {
		ans = min(ans, (c-a)+(b-c));
	}
	cout << ans <<endl;
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