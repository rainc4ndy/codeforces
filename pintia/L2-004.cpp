#include <bits/stdc++.h> 
#include <cstdio>

/*思路：
1. 按照二叉搜索树的性质，从前序中构造出二叉搜索树
2. 检查是否为有效的二叉搜索树
3. 如果无效，那么按照镜像后的二叉搜索树的性质，从镜像后的前序 构造出镜像后的二叉搜索树
4. 检查是否是镜像后的二叉搜索树*/

using namespace std;

#define SZ (1001)

struct node {
	int id;
	node *l, *r;
	node(int i = -1): id(i), l(nullptr), r(nullptr) {}
};

node mem[SZ] {}; //用来构建二叉树，不用vector是因为vector大小改变后会重新分配内存，导致指针变化
int mem_len = 0;

int order[SZ] {}; //输入序列

int order_ans[SZ] {}; //输出序列
int ans_len = 0;

bool mirror = false;

//如果mirror = true，那么这里生成镜像后的二叉树 (输入的序列也必须是镜像后的前序)
void build_bst(node *r_node, int start, int end) {
	if (start + 1 >= end)
		return;

	int root = order[start];
	int slice_start = start + 1;
	int i = slice_start;
	
	if (!mirror) {
		for (; i < end; i++) {
			if (order[i] >= root)
				break;
		}
	} else {
		for (; i < end; i++) {
			if (order[i] < root)
				break;
		}
	}
	
	if (end - slice_start == 1) {
		//子树下只有一个节点
		mem[mem_len++] = node(order[slice_start]);
		if (!mirror) {
			if (order[start + 1] < root) {
				r_node->l = &mem[mem_len - 1];
			} else {
				r_node->r = &mem[mem_len - 1];
			}
		} else {
			if (order[start + 1] >= root) {
				r_node->l = &mem[mem_len - 1];
			} else {
				r_node->r = &mem[mem_len - 1];
			}
		}
	} else {
		mem[mem_len++] = node(order[slice_start]); // (如果mirror，那么order[start+1 -> i] 全部比r_node->id要大)
		node *l_root = &mem[mem_len - 1];

		mem[mem_len++] = node(order[i]);
		node *r_root = &mem[mem_len - 1];

		r_node->l = l_root;
		r_node->r = r_root;

		build_bst(l_root, slice_start, i);
		build_bst(r_root, i, end);
	}
}

//如果mirror = true，那么这里检查：是否是一棵镜像后的二叉搜索树
bool traverse_bst(node *root) {
	if (root != nullptr) {
		if (root->l != nullptr) {
			if (!mirror) {
				if (root->l->id > root->id)
					return false;
			} else if (root->l->id <= root->id)
				return false;
		}
		if (root->r != nullptr) {
			if (!mirror) {
				if (root->r->id <= root->id)
					return false;
			} else if (root->r->id > root->id)
				return false;
		}
		return traverse_bst(root->l) && traverse_bst(root->r);
	}
	return true;
}

// 后序遍历
void traverse_b_order(node *root) {
	if (root != nullptr) {
		traverse_b_order(root->l);
		traverse_b_order(root->r);
		order_ans[ans_len++] = root->id;
	}
}

void printans() {
	for (int i = 0; i < ans_len; i++) {
		cout << order_ans[i];
		if (i != ans_len - 1)
			cout << ' ';
	}
}

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n;
    cin >> n;

   	for (int i = 0; i < n; i++)
   		cin >> order[i];

   	//插入根节点
   	mem[mem_len++] = node(order[0]);
   	node *root = &mem[mem_len - 1];
   	build_bst(root, 0, n);

   	bool judge = traverse_bst(root);

   	if (judge) {
   		cout << "YES" << endl;
   		traverse_b_order(root);
   		printans();
	} else {
		//二次检查
		mirror = true;
	   	mem_len = 1; //之前插入过根节点了
	   	
	   	build_bst(root, 0, n);

	   	judge = traverse_bst(root);

		if (judge) {
			cout << "YES" << endl;
			traverse_b_order(root);
   			printans();
		} else {
			cout << "NO";
		}
	}

	return 0;
}