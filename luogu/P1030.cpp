#include <bits/stdc++.h>
using namespace std;

string in, post;

struct node {
	int v;
	node *lch, *rch;
	node(int n ): v(n), lch((nullptr)), rch(nullptr) {}
};

int t = 0;

void build(int l, int r,  int &t, node *&root) {
	int id = -1;
	for (int i = l; i < r; i++) {
		if (in[i] == post[t]) {
			id = i;
			break;
		}
	}

	if (id == -1)
		return;

	root = new node(in[id]);
	t--;

	if (id < r)
		build(id, r, t, root->rch);
	if (id > l)
		build(l, id, t, root->lch);
}

void dfs(node *root) {
	if (!root)
		return;

	cout << (char)root->v;
	dfs(root->lch);
	dfs(root->rch);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> in >> post;

	node *root;
	t = post.size()-1;
	build(0, post.size(), t, root);
	dfs(root);

	return 0;
}