#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

vector<vector<P>> graph(2001, vector<P>());
vector<vector<int>> dp(2001, vector<int>(2001, 0));

void solve() {
	int n,k,x,y,z;
	cin >> n >> k;

	/*

		dp[3][k] = 0

		dp[1][1] = dp[2][1] + v(1,2) + v(1,5)

		dp[2][1] = 
		dp[2][2] =
	*/

	auto dfs = [&](auto&& self, int x) {
		int mx = min(static_cast<int>(graph[x].size()), k);
		for (int i = 0; i < graph[x].size(); i++) {
			self(self, graph[x][i].x);
			dp[x][i]
		}
		return;
	};

	for (int i = 0; i < n; i++) {
		cin >>x >> y >> z;
		graph[x].emplace_back(y,z);
		graph[y].emplace_back(x,z);
	}

	dfs(dfs, 1);
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}