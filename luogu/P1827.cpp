#include <bits/stdc++.h> 
using namespace std;

string pre, mid;
struct node {
	char c;
	node *lch, *rch;
	node(int i): c(i), lch(nullptr), rch(nullptr) {}
};

int loc = 0;

void build(int l, int r, int &n, node* &root) {
	int flag = -1;
	for (int i = l; i < r; i++) {
		if (mid[i] == pre[n]) {
			flag = i;
		}
	}

	if (flag == -1)
		return;

	root = new node(mid[flag]);
	n++;

	if (flag > l)
		build(l, flag, n, root->lch);
	if (flag < r)
		build(flag, r, n, root->rch);

}

void dfs(node *root) {
	if (!root)
		return;
	dfs(root->lch);
	dfs(root->rch);
	cout << (char)root->c;

}
int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	cin >> mid >> pre;	

	node *root = new node(pre[0]);
	build(0, pre.size(), loc, root);
	dfs(root);
	return 0;
} 