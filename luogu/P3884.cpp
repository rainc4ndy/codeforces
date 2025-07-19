#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int SZ = 256;

int lch[SZ] {}, rch[SZ] {};
int width[SZ] {};

int dfs_depth(int root, int r) {
	if (!root)
		return r;

	width[r]++;

	return max(
		dfs_depth(lch[root], r+1),
		dfs_depth(rch[root], r+1)
		);
}

//vector<int> path;
int lca(int root, int a, int b) {
	if (!root)
		return -1;

	if (root == a || root == b) {
		//path.push_back(root);
		return root;
	}

	int l = lca(lch[root], a, b);
	int r = lca(rch[root], a, b);

	if (l != -1 && r != -1)
		return root;
	if (r != -1) {
		//path.push_back(root);
		return r;
	}
	if (l != -1) {
		//path.push_back(root);
		return l;
	}
	return -1;
}

int dfs_dis(int root, int a, int r) {
	if (!root)
		return 0x3f3f3f3f;
	if (root == a)
		return r;

	return min(
		dfs_dis(lch[root], a, r+1),
		dfs_dis(rch[root], a, r+1)
		);
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n;
	cin >> n;

	int x, y;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		if (!lch[x])
			lch[x] = y;
		else if (!rch[x])
			rch[x] = y;

	}
	cin >> x >> y;

	int mx = 0, dep = dfs_depth(1, 0);
	for (int i = 1; i <= dep; i++) {
		mx = max(mx, width[i]);
	}
	cout << dep << endl << mx << endl;
	int pa = lca(1, x, y);
	int dis = dfs_dis(pa, x, 0) + dfs_dis(pa, y, 0);
	/*for (auto it : path) {
		if (!lch[it] && !rch[it]) {
			cout << "it =" << it<< endl;
			dis++;
		}
	}*/
	cout << dis; 

	return 0;
}