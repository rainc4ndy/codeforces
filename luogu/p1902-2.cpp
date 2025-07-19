#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1010;
int n, m, map[N][N], l, r, mid, x, y;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
bool flag = 0, vis[N][N];

void dfs(int xx, int yy) {
	if(xx == n-1) {flag = 1;return;}
	for(int i = 0; i < 4; i++) {
		x = xx + dx[i], y = yy + dy[i];
		if(x >= 0 && x < n && y >= 0 && y < m && map[x][y] <= mid && !vis[x][y]) {
			vis[x][y] = 1;
			dfs(x, y);
			vis[x][y] = 0;
			if(flag) break;
		}
	}
}
bool check(int x) {
	flag = 0;
	memset(vis, 0, sizeof(vis));
	dfs(0, 0);
	if(flag) return 1;
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++)
			cin >> map[i][j], r = max(r, map[i][j]);

	int ans = 0;
	while(l <= r) {
		mid = (l + r) >> 1;
		if(check(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}