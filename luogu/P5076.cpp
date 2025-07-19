#include <bits/stdc++.h> 
using namespace std;

#define ll long long

struct node {
	ll v;
	node *lch, *rch;
	node(ll n ): v(n), lch(nullptr), rch(nullptr) {

	}
};

map<ll, int> um;

void ins(ll n, node *&root) {
	if (!root) {
		root = new node(n);
		return;
	}
	if (n < root->v) {
		ins(n, root->lch);
	}
	if (n > root->v) {
		ins(n, root->rch);
	}
} 

ll dfs_least(ll trg, node *root) {
    if (root == nullptr) {
        return 0;
    }

    // 如果当前节点值小于x，则当前节点和其左子树中的所有节点都计数
    if (root->v < trg) {
        // 1 是当前节点，递归左子树和右子树
        return 1 + dfs_least(trg, root->lch) + dfs_least(trg, root->rch);
    } else {
        // 如果当前节点值大于或等于x，则只需要考虑左子树
        return dfs_least(trg, root->lch);
    }
}

ll dfs_q(ll level, node *rr, node *root) {
	if (!root) {
		return 0;
	}

	ll r;
	if (um[root->v] != 0)
		r = um[root->v];
	else {
		r= dfs_least(root->v, rr) + 1;
	}

	if (level == r)
		return root->v;

	ll ans;
	ans = dfs_q(level, rr, root->lch);
	if (ans)
		return ans;
	return dfs_q(level, rr, root->rch);
}

int dfs_mx(ll trg, node *root, ll mx) {
	if (!root)
		return mx;

	if (root->v < trg) {
		mx = max(mx, root->v);
	} 

	return max(
		dfs_mx(trg, root->lch, mx),
		dfs_mx(trg, root->rch, mx)
	);
}

int dfs_mi(ll trg, node *root, ll mi) {
	if (!root)
		return mi;

	if (root->v > trg) {
		mi = min(mi, root->v);
	} 

	return min(
		dfs_mi(trg, root->lch, mi),
		dfs_mi(trg, root->rch, mi)
	);
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	ll q;
	cin >> q;
	ll x, y;

	ll inf = 2147483647;

	vector<ll> ans;
	node *root = nullptr;
	for (int i = 0 ; i < q; i++) {
		cin >> x >> y;
		if (x == 5) {
			ins(y, root);
		} else {
			switch (x) {
				case 1: {
					int r = dfs_least(y, root) + 1;
					ans.push_back(r);
					um[y] = r;
					break;
				}
				case 2: {
					ans.push_back(dfs_q(y, root, root));
					break;
				} 
				case 3: {
					ll r = dfs_mx(y, root, -inf);
					ans.push_back(r);
					break;
				}
				case 4: {
					ll r = dfs_mi(y, root, inf);
					ans.push_back(r);
					break;
				}
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i != ans.size()-1)
			cout << endl;
	}

	return 0;
}