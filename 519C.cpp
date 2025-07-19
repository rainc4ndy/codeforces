#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n,m; cin >> n >> m;

	int ans =0;
	while (n+m>=3 && n > 0 && m > 0) {
		if (m > n) {
			m -= 2;
			n--;
			ans++;
		} else {
			n -= 2;
			m--;
			ans++;
		}
	}
	cout << ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}