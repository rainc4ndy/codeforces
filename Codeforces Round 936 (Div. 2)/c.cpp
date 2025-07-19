#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define SZ (100000)

int lch[SZ] {}, rch[SZ] {};

int dfs_depth(int root, int d) {
	if (!root)
		return d;
	
	return max(
	           dfs_depth(lch[root], d + 1),
	           dfs_depth(rch[root], d + 1)
	       );
}

int find_by_depth(int root, int pre, int depth, int current) {
/*	cout << "current = " << current << endl;
	cout << "depth = " << depth << endl;
*/
	if (!root)
		return 0;

	if (depth == current) {
		cout << "removed " << root << endl;
		if (lch[pre] == root)
			lch[pre] = 0;
		if (rch[pre] == root)
			rch[pre] = 0;
		return 1;
	}

	if (lch[root]) {
		int r = find_by_depth(lch[root], root, depth, current + 1);
		if (r) {
			return 1;
		}
	}
	if (rch[root]) {
		int r = find_by_depth(rch[root], root, depth, current + 1);
		if (r) {
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	
	cin >> t;
	vector<int> ans(t);

	int n, k, x , y;

	for (int i = 0; i < t; i++) {
		cin >> n >> k;

		memset(lch, 0, sizeof(lch));
		memset(rch, 0, sizeof(rch));
		for (int j = 0; j < n - 1; j++) {
			cin >> x >> y;

			if (!rch[x])
				rch[x] = y;
			else if (!lch[x])
				lch[x] = y;
		}

		for (int j = 0; j < k; j++) {
			int r = dfs_depth(1, 0);
			find_by_depth(1, 1, r /2, 0);
		}

		cout << dfs_depth(1, 0);
	}

	for (int i =0; i < t; i++) {
		cout << ans[i];
		if (i != t-1)
			cout << endl;
	}

	return 0;
}