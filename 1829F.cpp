#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

vector<int> adj[1001];
bool vis[201] {};

//check if it's center
bool dfs(int root, int step) {
	if (step == 2) {
		if (adj[root].size() == 1)
			return true;
		else 
			return false;
	} else {
		for (int i = 0; i < adj[root].size(); i++) {
			vis[adj[root][i]] = true;
			if (dfs(adj[root][i], step+1)) {
				return true;
			}
			vis[adj[root][i]] = false;
		}	
		return false;
	}
}

void solve() {
	int n,m;
	cin >> n >> m;

	int p1,p2;
	for (int i = 0; i <= n; i++) {
		adj[i].clear();
	}
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2; 
		adj[p1].push_back(p2);
		adj[p2].push_back(p1);
	}
	memset(vis, 0, sizeof(vis));

	for (int i = 1; i <= n; i++) {
		if (adj[i].size() > 1) {
			vis[i] = true;
			if (dfs(i, 0)) {
				cout << adj[i].size() << ' ' << adj[adj[i][0]].size()-1 << endl;
				break;
			} else {
				vis[i] = false;
			}
		}
	}
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