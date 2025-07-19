#include <bits/stdc++.h> 
#include <queue>
using namespace std;

#define mod (100005)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

vector<int> e[mod]{};
bool vis[mod] {};
int n,m;

void dfs(int root) {
	cout << root << ' ';
	vis[root] = true;

	for (int i = 0; i < e[root].size(); i++) {
		if (vis[e[root][i]])
			continue;
		
		dfs(e[root][i]);
	}
}

void bfs(int root) {
	queue<int> q;
	q.push(root);
	vis[root] = true;

	int current;
	while (!q.empty()) {
		current = q.front();
		q.pop();

		cout << current << ' ';

		for (int i = 0; i < e[current].size(); i++) {
			if (vis[e[current][i]])
				continue;

			vis[e[current][i]] = true;

			q.push(e[current][i]);
		}
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	cin >> n >> m;

	int x, y;
	set<int> ss;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		e[x].push_back(y);
		ss.insert(x);
	}

	for (auto it : ss) {
		sort(e[it].begin(), e[it].end());
	}

	dfs(1);
	memset(vis, 0, sizeof(vis));
	cout << endl;
	bfs(1);
	return 0;
}