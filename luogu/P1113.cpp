#include <bits/stdc++.h> 
#include <queue>
#include <vector>
using namespace std;

#define mod (10001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int n;
vector<int> e[mod] {};
int t[mod] {};
bool vis[mod] {};

vector<int> tp;
int din[mod] {};

int toposort() {
	queue<int> q;

	for (int i = 0; i < n; i++) {
		if (!din[i])
			q.push(i);
	}

	int cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int i = 0;)
	}
}

int bfs(int root) {
	int ans = t[root];

	queue<int> q;
	q.push(root);
	vis[root] = true;

	int cur = 0;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		int mx = 0;
		for (int i = 0; i < e[cur].size(); i++) {
			if (vis[e[cur][i]])
				continue;
			mx = max(t[e[cur][i]], mx);
			vis[e[cur][i]] = true;
			q.push(e[cur][i]);
		}
		//cout << "mx = " << mx << endl;
		ans += mx;
	}
	return ans;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int x, y, z;
    int root = 0;
    cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		t[x] = y;
		if (z) {
			e[z].push_back(x);
			din[x]++;
			for (;;) {
				cin >> z;
				if (z) {
					e[z].push_back(x);
					din[x]++;
				} else {
					break;
				}
			}
		}
		else {
			root = x;
		}
	}

	cout << bfs(root);

	return 0;
}