#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair< int,  int> P;

int dp[60001];
P d[60001];

void solve() {
	int n,v;
	cin >> n >> v;

	for ( int i = 1; i <= n; i++) {
		cin >> d[i].x >> d[i].y;
	}	
	for ( int i= 1; i <= n; i++) {
		for ( int j = v; j >= d[i].x; j--) {
			dp[j] = max(dp[j], dp[j-d[i].x] + d[i].y);
		}
	}

	cout << dp[v];
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}