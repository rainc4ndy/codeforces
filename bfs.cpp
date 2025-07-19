#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

struct node {
	bool visit;
	int distance;
	int path;
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> edges = {
		{1},
		{0, 2, 3}, //1
		{1, 4}, //2 
		{1, 4}, // 3
		{2, 3, 5}, //4 
		{4} // 5
	};

	int start = 5;
	int end = 0;

	// init
	vector<node> nv; //vertex, visit, dist, path.
	node tmp;
	tmp.visit = false;
	tmp.distance = 0;
	for (int i = 0; i < 6; i++)
		nv.push_back(tmp);

	queue<int> q;
	q.push(start);

	cout << "generating" << endl;
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		// 应该在这里标记u为已访问
		//nv[u].visit = true; // 标记当前节点为已访问

		//遍历所有邻接顶点
		int sz = edges[u].size();
		for (int i = 0; i < sz; i++) {
			if (!nv[edges[u][i]].visit) {
				nv[edges[u][i]].distance = nv[u].distance + 1; // 应该是等于u的distance加1，而不是自增

				//将v的前驱节点设置为u
				nv[edges[u][i]].path = u;
				q.push(edges[u][i]); //数字表示

				// 这里应该标记edges[u][i]为已访问，但是正确的做法是在这个节点实际出队列时标记
				// 所以这行注释掉
				nv[edges[u][i]].visit = true;
			}
		}
	}

	cout << "generating path" << endl;

	vector<int> path;

	int p = end;
	while (p != start) {
		path.push_back(p);
		p = nv[p].path;
	}
	path.push_back(start);

	reverse(path.begin(), path.end());

	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << " -> ";
	}

	return 0;
}