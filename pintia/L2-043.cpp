#include <bits/stdc++.h> 
#include <queue>
#include <vector>
using namespace std;

const int SZ = 1e5+1;
const int INF = 0x3f3f3f3f;

vector<int> u[SZ];
bool flag[SZ] {}; //target
int adj[SZ] {};

vector<pair<int, bool>> loc;


/*int dfs_dis(int root, int cnt) {
	if (flag[root]) {
		cnt++;
	}

	if (u[root].size() == 0)
		return cnt;
	
	int r = INF;
	for (int i = 0; i < u[root].size(); i++) {
		r += dfs_dis(u[root][i], cnt);
	}
	return r;
}

void dfs(int root) {
	if (u[root].size() ==0)
		return;

	int dis = 0;
	vector<pair<int, int>> v;
	for (int i = 0; i < u[root].size(); i++) {
		dis = dfs_dis(u[root][i], 0);
	}
}*/

void bfs(int source) {
	queue<int> q;
	q.push(source);
	adj[source] = 0;

	int cur = 0;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		//cout << "cur = " << cur << endl;
		for (auto it : u[cur]) {
			adj[it] = adj[cur] + 1;
			if (flag[it]) {
				cout << it << " -> " << adj[it] << endl;
			}
			q.push(it);
		}
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n,m;
	cin >> n >> m;

	vector<int > ans(m);

	int root = -1;

	int x; 

	for (int i = 0; i< n; i++) {
		cin >> x;
		if (x == -1)
			root = i + 1;
		else 
			u[x].push_back(i+1);
	}

	for (int i = 0; i < m; i++) {
		cin >> x;
		flag[x] = true;
	}

	bfs(root);

	return 0;
}