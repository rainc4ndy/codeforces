#include <bits/stdc++.h> 
#include <functional>
#include <queue>
#include <vector>
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int n,m;
vector<int> e[mod];

bool vis[mod] {};

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	cin >> n >> m;
	int x, y;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	vector<int> ans;
	priority_queue<int, vector<int>, greater<int>> q;

	q.push(1);
	vis[1] = true;

	int cur = 0;
	while (!q.empty()) {
		cur = q.top();
		ans.push_back(cur);
		q.pop();

		for (int i = 0; i < e[cur].size(); i++) {
			if (vis[e[cur][i]])
				continue;
			q.push(e[cur][i]);
			vis[e[cur][i]] = true;
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}