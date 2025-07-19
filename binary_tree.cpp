#include <iostream>

// 二叉树节点类
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // 构造函数
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// 二叉树类
class BinaryTree {
private:
    TreeNode* root;

    // 插入节点的辅助函数
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // 中序遍历的辅助函数
    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    // 构造函数
    BinaryTree() : root(nullptr) {}

    // 插入节点
    void insert(int value) {
        root = insert(root, value);
    }

    // 中序遍历
    void inorderTraversal() {
        inorderTraversal(root);
    }
};

int main() {
    BinaryTree tree;

    // 插入节点
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    // 中序遍历
    std::cout << "Inorder Traversal: ";
    tree.inorderTraversal();
    std::cout << std::endl;

    return 0;
}
