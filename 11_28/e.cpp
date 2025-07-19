#include <bits/stdc++.h>
#include <queue>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

vector<P> dir = {
	{2, 1},
	{ -2, 1},
	{ -2, -1},
	{2, -1},
	{1, 2},
	{1, -2},
	{ -1, 2},
	{ -1, -2}
};

bool vis[64][64] {};
int n, m, x, y;
int j, k;
int ans = 0x3f3f3f3f;

void bfs() {
	queue<int> q;
	q.emplace(x, y, 0);
	while(!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.x == j && cur.y == k) {
			ans = min(ans, cur.z);
			continue;
		}

		for (auto& it : dir) {
			int a = cur.x + it.x, b = cur.y + it.y;
			if (a < 0 || a >= n ||b < 0 ||b >= m) {
				continue;
			} 
			if (vis[a][b])
				continue;
			vis[a][b] = true;
			q.emplace(a, b, cur.z+1);
		}
	}
}

void solve() {
	cin >> n >> m >> x >> y;
	cin >> j >> k;
	bfs();

	if (ans == 0x3f3f3f3f) cout << 0;
	else
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _ = 1;
	while (_--) solve();

	return 0;
}