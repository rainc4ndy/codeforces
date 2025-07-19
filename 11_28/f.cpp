#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

vector<vector<int>> g(100, vector<int>());
bool vis[100] {};
int n,m;
int cnt = 0;
void dfs(int x) {
	cnt++;
	for (auto it : g[x]) {
		if (vis[it])
			continue;
		dfs(it);
	}
}

void solve() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	} 

	if (cnt == m)
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