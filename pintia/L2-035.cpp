#include <bits/stdc++.h>
#include <queue>
using namespace std;

const int SZ = 32;
int v[SZ] {}, len;
int n;

void heaplify(int num) {
	v[++len] = num;
	int pos = len;

	while (pos > 1) {
		if (v[pos] < v[pos / 2]) {
			swap(v[pos], v[pos / 2]);
			pos /= 2;
			continue;
		}
		break;
	}
}


struct node {
	int v;
	node *lch, *rch;
	node(int n): v(n), lch(nullptr), rch(nullptr) {}
};

node *build(int root) {
	if (root < 1)
		return nullptr;

	int lch = root / 2;
	int rch = root / 2 + 1;

	node *obj = new node(v[root]);
	obj->lch = build(lch);
	obj->rch = build(rch);
	return obj;
} 

void bfs(node *root) {
	queue<node*> q;
	q.push(root);

	node *current;

	while (!q.empty()) {
		cout << current->v << ' ';

		current = q.front();
		q.pop();

		if (current->lch != nullptr)
			q.push(current->lch);
		if (current->rch != nullptr)
			q.push(current->rch);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (unsigned i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	node *root = build(n);
	cout << "cur root " << root->v << endl;
	bfs(root);

	return 0;
}