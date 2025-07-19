#include <bits/stdc++.h>

using namespace std;

struct node {
	int v;
	node *lch, *rch;
	node(int n): v(n), lch(nullptr), rch(nullptr) {}
};

node *ins(node *root, int id) {
	if (!root) {
		return new node(id);
	}

	if (id < root->v) {
		root->lch = ins(root->lch, id);
	}
	if (id > root->v) {
		root->rch = ins(root->rch, id);
	}

	return root;
}

void dfs(node *root) {
	if (nullptr == root)
		return;

	cout << root->v << ' ';
	dfs(root->lch);
	dfs(root->rch);
}

int dfs_p(node *root, int v, int pre) {
	if (nullptr == root)
		return -1;

	if (root->v == v)
		return pre;
	int r = dfs_p(root->lch, v, root->v);
	if (r != -1)
		return r;
	return dfs_p(root->rch, v, root->v);
}

int dfs_depth(node *root, int v, int d) {
	if (nullptr == root)
		return -1;

	if (root->v == v) {
		return d;
	}

	return max(
	           dfs_depth(root->rch, v, d + 1),
	           dfs_depth(root->lch, v, d + 1)
	       );
}

node *dfs_g(node *root, int v) {
	if (nullptr == root)
		return nullptr;

	if (root->v == v)
		return root;

	node *r = dfs_g(root->lch, v);
	if (r != nullptr)
		return r;
	return dfs_g(root->rch, v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> d(n);

	node *root = nullptr;
	for (unsigned i = 0; i < n; ++i) {
		cin >> d[i];
		if (i == 0) {
			root = ins(root, d[i]);
		} else {
			ins(root, d[i]);
		}
	}

	int k;
	string s;
	stringstream ss;
	cin >> k;

	cin.ignore();
	int x, y;
	vector<bool> ans(k);
	for (int i = 0; i < k; i++) {
		std::getline(cin, s);
		ss.clear();
		ss.str(s);
		if (s.find("root") != string::npos) {
			int r;
			ss >> r;
			ans[i] = root->v == r;
		} else if (s.find("siblings") != string::npos) {
			ss >> x;
			ss.ignore(5);
			ss >> y;

			if (x == y)
				ans[i] = false;
			else
				ans[i] = dfs_p(root, x, root->v) == dfs_p(root, y, root->v);
		} else if (s.find("same level") != string::npos) {
			ss >> x;
			ss.ignore(5);
			ss >> y;
			int g1 = dfs_depth(root, x, 0);
			int g2 = dfs_depth(root, y, 0);
			ans[i] = g1 == g2 && g1 != -1 && g2 != -1;
		} else if (s.find("parent") != string::npos) {
			ss >> x;
			ss.ignore(18);
			ss >> y;

			if (x == y)
				ans[i] = false;
			else
				ans[i] = x == dfs_p(root, y, root->v);
		} else if (s.find("left") != string::npos) {
			ss >> x;
			ss.ignore(22);
			ss >> y;

			if (x == y)
				ans[i] = false;
			else {
				node *tmp = dfs_g(root, y);
				if (!tmp)
					ans[i] = false;
				else {
					if (tmp->lch != nullptr)
						ans[i] = tmp->lch->v == x;
					else
						ans[i] = false;
				}
			}

		} else if (s.find("right") != string::npos) {
			ss >> x;
			ss.ignore(23);
			ss >> y;

			if (x == y)
				ans[i] = false;
			else {
				node *tmp = dfs_g(root, y);
				if (!tmp)
					ans[i] = false;
				else {
					if (tmp->rch != nullptr)
						ans[i] = tmp->rch->v == x;
					else
						ans[i] = false;
				}
			}
		}
	}

	for (int i = 0; i < k; i++) {
		cout << (ans[i] ? "Yes" : "No");
		if (i != k - 1)
			cout << endl;
	}



	return 0;
}