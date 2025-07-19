#include <bits/stdc++.h> 

using namespace std;

#define SZ (21)

int bombs[SZ] {}; //地雷数量
int edges[SZ][SZ] {}; //邻接矩阵

int n; //地窖数量

int mx[SZ][SZ] {}; //mx[a][b] 以节点a为出发点，挖到节点b能挖到最多的地雷数量
int path[SZ][SZ] {};

int root; //当前遍历的节点 (出发点)

int dfs(int s) {
	int reward_next = 0;
	for (int j = 0; j < n; j++) {
		if (edges[s][j] == 1) {
			reward_next = max(reward_next, dfs(j));

			printf("root = %d; mx[root][s] = %d; reward_next = %d; mx[root][j] = %d\n", root, mx[root][s], reward_next, mx[root][j]);
			if (mx[root][s] + reward_next > mx[root][j]) {
				mx[root][j] = mx[root][s] + reward_next;
				path[root][j] = s;
				printf("lnk %d to %d, re = %d\n", s + 1, j + 1, mx[root][j]);
			}
		}
	}

	return bombs[s] + reward_next;
}

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    cin >> n;

 	for (int i = 0; i < n; i++) {
 		cin >> bombs[i];
 		memset(path[i], -1, n);
 	}

 	int tmp;
 	for (int i = 0; i < n - 1; i++) {
 		for (int j = i + 1; j < n; j++) {
 			// tmp: 第i个地窖连接到第j个地窖的状态 (j = i + 1)
 			cin >> tmp;
 			if (tmp == 1) {
 				edges[i][j] = 1; //有向图
 			}
 		}
 	}

 	//source point
 	int r = 0, root_reward = 0, max_root_reward;
 	for (root = 0; root < n; root++) {
 		root_reward = dfs(root);
 		if (root_reward > max_root_reward) {
 			r = root;
 			max_root_reward = root_reward;
 		}
 	}

 	//end point
 	int e = 0, e_total = 0;
 	for (int i = 0; i < n; i++) {
 		if (mx[r][i] > e_total) {
 			e = i;
 			e_total = mx[r][i];
 		}
 	}

 	cout << "start = " << r + 1<< endl;
 	cout << "end = " << e + 1 << endl;

 	int ans[SZ] {};
 	int al = 0;

 	int ptr = e;
 	ans[al++] = e;
 	while (ptr != r) {
 		ans[al++] = path[r][ptr];
 		ptr = path[r][ptr];
 	}
 	ans[al++] = r;

 	for (int i = al - 1; i >= 0; i--) {
 		cout << ans[i] + 1 << ' ';
 	}

 	cout << endl << max_root_reward;

	return 0;
}