#include <bits/stdc++.h> 
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

//v, w
vector<int> v[1001], w[1001];
//有n种模式
//每种模式每日只能选用一种操作
//每日拥有体力M点，每日最多能得到多少收益

int dp[1001]; //dp[i] 体力为i的状态下，可获得的最大价值

void solve() {
	int n,m;
	cin >> n >> m; 

	memset(dp,0,sizeof(dp));
	for (int i = 0; i < n; i++) {
		int a; 
		cin >> a;
		
		v[i].resize(a);
		w[i].resize(a);
		
		for (int j = 0; j < a; j++)
			cin >> v[i][j];

		for (int j = 0; j < a; j++)
			cin >> w[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = m; j >= 0; j--) {
			for (int k = 0; k < v[i].size(); k++) {
				if(j >= w[i][k])
					dp[j] = max(dp[j], dp[j - w[i][k]] + v[i][k]);
			}
		}
	}

	cout << dp[m] << endl;
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