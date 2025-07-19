#include <bits/stdc++.h> 
 
using namespace std;

struct node {
	int id;
	node *left;
	node *right;
	node(int x): id(x), left(nullptr), right(nullptr) {}
};


node *binary_tree(node *root, vector<int> &d, int start, int end) {
	if (start == end)
		return nullptr;

	int mx = -1, mxi = -1;  
	for (int i = start; i < end; i++) {
		if (d[i] > mx) {
			mx = d[i];
			mxi = i;
		}
	}

	root = new node(mx);

	root->left = binary_tree(root, d, start, mxi);
	root->right = binary_tree(root, d, mxi + 1, end);

	return root;
}


int dfs(node* root, int target, int len) {
    if (root == nullptr) {
        return 0;
    }

    if (root->id == target) {
    	return len; //stop
    }

    int l = dfs(root->left, target, len + 1);
    int r = dfs(root->right, target, len + 1);

    return max(l, r);
}

int main() {
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t, n, tmp;

	cin >> t;

	vector<vector<int>> v(t);

	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			v[i].push_back(tmp);
		}
	}

	int sz;
	for (int i = 0; i < t; i++) {
		sz = v[i].size();
		
		//construct tree
		node *root = binary_tree(nullptr, v[i], 0, sz);
		for (int j = 0; j < sz; j++) {
			cout << dfs(root, v[i][j], 0);
			if (j != sz - 1) {
				cout << ' ';
			}
		}
		if (i != t - 1)
			cout << endl;
	}

	return 0;
}