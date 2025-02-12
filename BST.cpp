#include <iostream>
using namespace std;

// 定义二叉搜索树的节点结构
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// 定义二叉搜索树类
class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    // 插入节点
    void insert(int val) {
        root = insertRecursive(root, val);
    }

    // 中序遍历（递归）
    void inorderTraversal() {
        inorderRecursive(root);
        cout << endl;
    }

private:
    TreeNode* root;

    // 插入操作的递归实现
    TreeNode* insertRecursive(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
        if (val < node->value) {
            node->left = insertRecursive(node->left, val);
        } else if (val > node->value) {
            node->right = insertRecursive(node->right, val);
        }
        return node;
    }

    // 中序遍历的递归实现
    void inorderRecursive(TreeNode* node) {
        if (node != nullptr) {
            inorderRecursive(node->left);
            cout << node->value << " ";
            inorderRecursive(node->right);
        }
    }
};

int main() {
    BinarySearchTree bst;

    // 插入一些值
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
   .insert bst(70);
    bst.insert(60);
    bst.insert(80);

    // 中序遍历
    cout << "Inorder traversal of the BST: ";
    bst.inorderTraversal();

    return 0;
}