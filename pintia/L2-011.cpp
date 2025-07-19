#include <bits/stdc++.h>
using namespace std;

const int SZ = 31;

int in[SZ], pre[SZ];
int n, cnt;

struct node {
	int v;
	node *lch, *rch;
	node(int i): v(i), lch(nullptr), rch(nullptr) {}
};

//t表示当前在前序的第t个node
void buildTree(int l, int r, int &t, node* &root) {
	int id = -1;

	for(unsigned i = l; i < r; ++i) {
		if (in[i] == pre[t]) {
			id = i;
			break;
		}
	}

	if (id == -1)
		return;

	root = new node(in[id]);
	t++; //前序往后一个

	if (id > l)
		buildTree(l, id, t, root->lch); //取到id-1个，id是从0开始数的
	if (id < r)
		buildTree(id, r, t, root->rch);
}

//将所有非叶结点的左右孩子对换
void flipTree(node *root) {
	if (root == nullptr)
		return;

	if (root->lch == nullptr && root->rch == nullptr)
		return;

	node *tmp = root->lch;
	root->lch = root->rch;
	root->rch = tmp;
	flipTree(root->lch);
	flipTree(root->rch);
}

void bfs(node *root) {
	queue<node*> q;

	q.push(root);

	node *current;
	while (!q.empty()) {
		current = q.front();
		q.pop();

		cout << current->v;
		if (cnt++ != n-1)
			cout << ' ';

		if (current->lch)
			q.push(current->lch);
		if (current->rch)
			q.push(current->rch);
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n;
	for(unsigned i = 0; i < n; ++i) {
		cin >> in[i];
	}
	for(unsigned i = 0; i < n; ++i) {
		cin >> pre[i];
	}

	node *root;
	int t = 0;
	buildTree(0, n, t, root);
	flipTree(root);
	bfs(root);

	return 0;
}
