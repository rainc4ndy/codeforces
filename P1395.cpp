#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

int cnt[mod], dist[mod];
vector<int> graph[mod];

void dfs(int v, int p) {
	cnt[v] = 1;
	for (auto it : graph[v]) {
		if (it == p)
			continue;
		dfs(it, v);
		cnt[v] += cnt[it];
	}
}


void solve() {
	int n;

	int u, v;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(0, -1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _;
	cin >> _;
	while (_--)
		solve();

	return 0;
}