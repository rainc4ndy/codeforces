#include <bits/stdc++.h>
using namespace std;

vector<int> scale; //节点的放大倍数
vector<int> pre; //父节点
vector<double> strength; //每个节点的力量
vector<vector<int>> con; //边

double ans = 0;
double factor;

void bfs(int root) {
	queue<int> q;
	q.push(root);

	int current, nxt;
	while (!q.empty()) {
		current = q.front();
		q.pop();

		if (con[current].size() == 0) {
			strength[current] *= scale[current];
			ans += strength[current];
			continue;
		}

		for (int i = 0; i < con[current].size(); i++) {
			nxt = con[current][i];
			strength[nxt] = strength[current] - strength[current] * (factor / 100.0);
			q.push(con[current][i]);
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    con.resize(n);
    strength.resize(n);
    scale.resize(n);
    pre.resize(n);

    cin >> strength[0] >> factor;

    int k;
    for(int i = 0; i < n; i++) {
    	cin >> k;
	   	if (k == 0) {
	   		cin >> scale[i];
	   		continue;
	    }
	    con[i].resize(k);
    	for(int j = 0; j < k; j++) {
    		cin >> con[i][j];
    		pre[j] = i;
    	}
    }

    bfs(0);
    cout << (int)ans;

	return 0;
}
