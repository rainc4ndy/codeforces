#include <bits/stdc++.h> 
using namespace std;

const int SZ = 100000;

int v[SZ] {};
vector<int> edges[SZ] {};
bool vis[SZ] {};
int path[SZ] {};

int bfs(int source) {
	memset(vis, 0, sizeof(vis));
	memset(path, 0, sizeof(path));
	queue<int> q;

	q.push(source);
	vis[source] = true;
	int cur;
	int sum = 0;

	while(!q.empty()) {
	    cur = q.front();
	    q.pop();


	    for (int i = 0; i < edges[cur].size(); i++) {
	    	if (!vis[edges[cur][i]]) {
	    		vis[edges[cur][i]] = true;

	    		path[edges[cur][i]] = path[cur] + 1;
	    		sum += v[edges[cur][i]] * path[edges[cur][i]];

	    		q.push(edges[cur][i]);
	    	}
	    }
	}
	return sum;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n;
    cin >> n;

    int x, y;
    for (int i = 1; i <= n; i++) {
    	cin >> v[i] >> x >> y;
    	if (x) {
    		edges[i].push_back(x);
    		edges[x].push_back(i);

    	}
    	if (y) {
    		edges[i].push_back(y);
    		edges[y].push_back(i);
    	}
    	
    }

    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
    	ans = min(ans, bfs(i));
    }

    cout << ans;

	return 0;
}