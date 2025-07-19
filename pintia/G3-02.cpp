#include <bits/stdc++.h>
using namespace std;

const int SZ = 10000;

vector<int> u[SZ];
int n, m, k;

struct node {
	int id;
	bool vis;
	int path;

	node(int i ) : id(i), vis(false), path(0) {}
	node() {}
};
node adj[SZ] {};

int bfs(int source) {
	//cout << "source: " << source + 1 << endl;
	memset(adj, 0 , sizeof(adj));

	queue<node*> q;
	adj[source].id = source;
	adj[source].vis = true;
	q.push(&adj[source]);

	node *cur;

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int i = 0; i < u[cur->id].size(); i++) {
			if (adj[u[cur->id][i]].vis)
				continue;

			adj[u[cur->id][i]].vis = true;

			//cout << "visiting " << u[cur->id][i] << endl;

			adj[u[cur->id][i]].path = adj[cur->id].path + 1;
			adj[u[cur->id][i]].id = u[cur->id][i];
			q.push(&adj[u[cur->id][i]]);
		}
	}

	int mx_path = 0, r = 6666;
	for (int i = 0; i < n; i++) {
		if (adj[i].path > mx_path) {
			mx_path = adj[i].path;
			r = adj[i].id;
		} else if (adj[i].path == mx_path && adj[i].path != 0) {
			if (adj[i].id < r) {
				r = adj[i].id;
			}
		}
	}

	return r;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	int x, y;
	for (unsigned i = 0; i < m; ++i) {
		cin >> x >> y;
		x--;
		y--;
		u[x].push_back(y);
		u[y].push_back(x);
	}

	vector<int> ans(k);
	for (unsigned i = 0; i < k; ++i) {
		cin >> x;
		x--;
		ans[i] = bfs(x) + 1;
		if (ans[i] == 6667)
			ans[i] = 0;
	}

	for (unsigned i = 0; i < k; ++i) {
		cout << ans[i];
		if (i != k - 1)
			cout << endl;
	}


	return 0;
}