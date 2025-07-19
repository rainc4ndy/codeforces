#include <bits/stdc++.h>
#include <functional>
#include <random>
#include <vector>
using namespace std;

#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof (arr))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define random rnd(chrono::system_clock::now().time_since_epoch().count())
#define setdb(v) setprecision(v)
#define debug(x) cout << #x << ' ' << x << endl;
#define x first
#define y second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const ll mod = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m));
	vector<vector<bool>> vis(n, vector<bool>(m));

	pii dir[4] = {
		{ -1, 0}, // N
		{0, 1},  // E
		{1, 0},  // S
		{0, -1}  // W
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	auto ok = [&](int x, int y) -> bool {
		return x >= 0 && x < n && y >= 0 && y < m;
	};


	auto dfs = [&](auto && self, int x, int y) -> int {
		vis[x][y] = true;
		int tot = 1; // 起始就是 1（当前格子）

		for (int i = 0; i < 4; i++) {
			int dx = x + dir[i].x, dy = y + dir[i].y;
			if (!ok(dx, dy) || vis[dx][dy]) continue;

			int curr = v[x][y];
			int next = v[dx][dy];

			// bit 3: N, bit 2: E, bit 1: S, bit 0: W
			bool wall_here = (curr >> (3 - i)) & 1;
			bool wall_there = (next >> (3 - ((i + 2) % 4))) & 1;

			if (!wall_here && !wall_there) {
				tot += self(self, dx, dy);
			}
		}
		return tot;
	};


	vector<int> ans;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j]) {
				int d = dfs(dfs, i, j);
				if (d) {
					ans.emplace_back(d);
				}
			}
		}
	}

	sort(begin(ans), end(ans), greater<int>());
	for (auto it : ans ) {
		cout << it << ' ';
	}
}

int main() {

	bitset<4> bs(10);
	debug(bs);
	debug(bs[0]);
	int _ = 1;
	while (_--) solve();

	return 0;
}