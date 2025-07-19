#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

int n, m;
bool vis[3000];
vector<int> e[3000];

int c1, c2;
void dfs(int x, bool c) {
	vis[x] = true;

	if (c) c1++;
	else c2++;

	for (int i = 0; i < e[x].size(); i++) {
		if (vis[e[x][i]])
			continue;
		dfs(e[x][i], c ^ 1);
	}
}

void solve() {
	memset(vis, 0, sizeof(vis));
	cin >> n >> m;
	int x, y;

	c1 = 0, c2 = 0;
	for (int i = 1; i <= n; i++) {
		e[i].clear();
	}
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		e[x].push_back(y), e[y].push_back(x);
	}

	dfs(1, false);
	int r = min(c1, c2);

	if (r <= 10) cout << r << endl;
	else cout << "GG" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _;
	cin >> _;
	while (_--) solve();
	return 0;
}