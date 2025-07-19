#include <bits/stdc++.h> 
#include <iterator>
#include <vector>
using namespace std;

const int mod = 5e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

vector<int> v[mod];
bool vis[mod];
int dp[mod][2];
//dp[u][0] 表示以节点u为根，且u不在独立集中的最大独立集大小
//dp[u][0] 表示以节点u为根，且u在独立集中的最大独立集大小

void solve() {
	int n,s;
	cin >> n >> s;

	memset(dp, 0, sizeof(dp));
	memset(vis, 0, sizeof(vis));

	int x,y;
	for (int i = 0; i < n-1; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	auto dfs = [&](const auto &self, int x) -> void {
		vis[x] = true;
		for (auto &it : v[x]) {
			if (vis[it])
				continue;

			self(self, it);
			//如果x不在最大独立集里，那么它的子节点可以在独立集或不在
			dp[x][0] += max(dp[it][0], dp[it][1]);

			//如果x在，那么相邻的子节点就不能选
			dp[x][1] += dp[it][0];
		}
		dp[x][1]++;
	};	

	dfs(dfs, s);

	cout << dp[s][1] << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}