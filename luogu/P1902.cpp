#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define mod (1005)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int v[mod][mod] {};
bool vis[mod][mod] {};

int dir[4][2] = {
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};

int n, m;
bool ok;
int mid;
int x, y;

void dfs(int p1, int p2) {
	if (p1 == n-1) {
		ok = true;
		return;
	}

	for (int i = 0; i < 4; i++) {
		x = p1 + dir[i][0];
		y = p2 + dir[i][1];
		if (x < 0 || x >= n || y < 0 || y >= m)
			continue;
		if (v[x][y] > mid)
			continue;
		if (vis[x][y])
			continue;

		vis[x][y] = true;
		dfs(x, y);
		vis[x][y] = false;
		if (ok)
			break;
	}
}

bool ck() {
	ok = false;
	memset(vis,0,sizeof(vis));
	dfs(0, 0);
	return ok;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int l = 1, r = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			r = max(r, v[i][j]);
		}
	}

	int ans = 0;
	while (l <= r) {
		mid = (l+r)>>1;
		if (!ck()) {
			l = mid+1;
		} else {
			ans = mid;
			r = mid-1;
		}
	}

	cout << ans;

	return 0;
}