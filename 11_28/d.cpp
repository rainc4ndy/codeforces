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
	{ 0, 1},
	{ 1, 0},
	{ 0, -1},
	{ -1, 0}
};

bool vis[128][128] {};
bool wall[128][128] {};
int n, m, x, y;
int ans = 0x3f3f3f3f;
struct st {
	int x,y,z;
	st(int X, int Y, int Z) : x(X), y(Y), z(Z) {}
};


void bfs() {
	queue<st> q;
	q.emplace(1, 1, 0);
	while(!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.x == x && cur.y == y) {
			ans = min(ans, cur.z);
			continue;
		}

		for (auto& it : dir) {
			int a = cur.x + it.x, b = cur.y + it.y;
			if (a < 1 || a > n ||b < 1 ||b > m) {
				continue;
			} 
			if (vis[a][b] || wall[a][b])
				continue;
			vis[a][b] = true;
			q.emplace(a, b, cur.z+1);
		}
	}
}

void solve() {
	cin >> n >> m >> x >> y;

	for (int i = 1; i <= n;i++) {
		for (int z =1 ; z <= m; z++) {
			cin >> wall[i][z];
		}
	}
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