#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair< int,  int> P;


void solve() {
	cout << "test" << endl;
	short n,v;
	n = 5, v = 10;
	//cin >> n >> v;
	vector<vector< int>> dp(n + 1, vector< int>(v + 1));

	vector<P> d {
		{0, 0},
		{2, 1},
		{6, 4},
		{10, 5},
		{8, 4},
		{4, 2}
	};
	//for ( short i = 1; i <= n; i++) {
	//	cin >> d[i].x >> d[i].y;
	//}	

	//2 6 10 8 4
	//1 4 5 4 2
	dp[0][0] = 0;
	//dp[i][j]=max(dp[i−1][j],dp[i−1][j−wi]+vi)
	for ( int i= 1; i <= n; i++) {
		for ( int j = 1; j <= v; j++) {
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-d[i].x]+d[i].y);
		}
	}

	for ( int i= 1; i <= n; i++) {
		for ( int j = 1; j <= v; j++) { 
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << dp[n][v];
}

int main() {    
	cout << "started" << endl;
	int _ = 1;
	while(_--) solve();

	return 0;
}