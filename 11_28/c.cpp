#include <bits/stdc++.h>
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
int ans =0;

int dfs(int a, int b, int c) {
	cout << a << ' ' << b  << ' '<< c << endl;
	int ans = 0;
	if (a == j && b == k) {
		ans = min(ans, c);
		return c;
	}
	for (auto p : dir) {
		int a1 = a + p.x, a2 = b + p.y;
		if (a1 < 0 || a1 >= n || a2 < 0 || a2 >= m) {
			continue;
		}
		if (vis[a1][a2])
			continue;
		vis[a1][a2] = true;
		auto tt = dfs(a1,a2, c + 1);
		if (tt != -1) {
			vis[a1][a2] = false;
			return tt;
		}
		vis[a1][a2] = false;
	}
	return -1;
}

void solve() {
	cin >> n >> m >> x >> y;
	cin >> j >> k;
	if (dfs( x, y, 0) == -1) {
		cout << 0;
	} else 
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