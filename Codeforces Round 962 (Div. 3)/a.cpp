#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n;
	cin >> n;

	if (n % 4 == 0) {
		cout << n / 4 << endl;
	} else {
		if (n == 2) cout << 1 << endl;
		else {
			cout << (n % 4) + ((n / 4) / 2) << endl;
		}
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int t;
    cin >> t;
    while(t--)
    	solve();

	return 0;
}