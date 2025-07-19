#include <bits/stdc++.h> 
#include <utility>
#include <vector>
using namespace std;

const int SZ = 11;

int v[SZ][SZ] {};
bool vis[SZ][SZ] {};

int n, k;

typedef pair<int, int> P;
#define x first
#define y second

P dir[8] = {
	{-1, 0},
	{-1, 1},
	{0, 1},
	{1, 1},
	{1, 0},
	{1, -1},
	{0, -1},
	{-1, -1}
};

vector<int> path;

bool ok = false;
void dfs(int x, int y) {
	if (ok)
		return;

	if (x == n && y == n && path.size() == n*n-1) {
		for(auto it:path)cout<<it;cout<<endl;
		ok = true;
		return;
	}

	int p1,p2;
	int nxt = (v[x][y] + 1) % k;

	for (int i = 0; i < 8; i++) {
		p1 = x + dir[i].x;
		p2 = y + dir[i].y;

		if (p1 <= 0 || p1 > n) 
			continue;
		if (p2 <= 0 || p2 > n) 
			continue;

		if (vis[p1][p2]) 
			continue; 
		
		if (v[p1][p2] == nxt) {

			vis[p1][p2] = true;
			path.push_back(i);
			dfs(p1, p2);
			path.pop_back();
			vis[p1][p2] = false;
		}
	}
}

int main() {    

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> v[i][j];
		}
	}

	vis[1][1] = true;
	dfs(1, 1);
	if (!ok)
		cout << -1;

	return 0;
}