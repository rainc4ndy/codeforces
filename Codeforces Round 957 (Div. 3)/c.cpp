#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int v[mod];

void solve() {
	int n,m,k;
	cin >> n >> m >> k;

	for (int i = n; i >= k; i--) {
		cout << i << ' ';
	}

	for (int i = m+1; i <= k-1; i++) {
		cout << i << ' ';
	}

	for (int i = 1; i <= m; i++) {
		cout << i << ' ';
	}
	cout << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;

	while (t--)
		solve();

	return 0;
}