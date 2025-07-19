#include <bits/stdc++.h>
#include <queue>
using namespace std;

const int mod = 1e6 + 10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

char v[31][31];
bool vis[31][31];
int s1, s2, e1, e2;

struct node {
	P p;
	node* f;
	node(P p1, node* p2) : p(p1), f(p2) {}
};

P df[8] = {
	{0, 1},
	{0, -1},
	{1, 0},
	{1, -1},
	{ -1, -1},
	{ -1, 1},
	{ -1, 0},
	{1, 1},
};

P di[4] = {
	{0, 1},
	{1, 0},
	{ -1, 0},
	{0, -1}
};

void solve() {
	int n, m;
	cin >> n >> m;

	memset(vis, 0, sizeof(vis));
	memset(v, 0, sizeof(v));

	for (int i = 0; i < n; i++) {
		for (int j = 0 ; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 'S') s1 = i, s2 = j;
			else if (v[i][j] == 'E') e1 = i, e2 = j;
		}
	}

	queue<P> fire;
	for (int i = 0; i < n; i++) {
		for (int j = 0 ; j < m; j++) {
			if (v[i][j] == '*') {
				vis[i][j] = true; 
				fire.push({i, j});
			}
		}
	}

	while (!fire.empty()) {
		P block = fire.front();
		vis[block.x][block.y] = true; 
		fire.pop();
		for (int i = 0; i < 8; i++) {
			int p1 = block.x + df[i].x, p2 = block.y + df[i].y;
			if (p1 < 0 || p1 > n || p2 < 0 || p2 > m)
				continue;
			if (v[p1][p2] == 'E' || v[p1][p2] == '*')
				continue;
			if (vis[p1][p2])
				continue;
			fire.push({p1, p2});
		}
	}

	memset(vis, 0, sizeof(vis));
	queue<node*> q;
	q.push(new node({s1, s2}, nullptr));
	vis[s1][s2] = true;

	node* cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		if (cur->p.x == e1 && cur->p.y == e2) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			int p1 = cur->p.x + di[i].x, p2 = cur->p.y + di[i].y;
			if (p1 < 0 || p1 > n || p2 < 0 || p2 > m)
				continue;
			if (vis[p1][p2])
				continue;
			if (v[p1][p2] == '#' || v[p1][p2] == '*')
				continue;

			vis[cur->p.x][cur->p.y] = true;
			q.push(new node({p1, p2}, cur));
		}
	}

	if (cur->p.x != e1 && cur->p.y != e2) cout << "T_T" << endl;
	else {
		int ans = 0;
		while (cur->f) {
			ans++;
			cur = cur->f;
		}
		cout << ans << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}
