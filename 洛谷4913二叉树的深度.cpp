#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 二叉树节点结构体
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 构建二叉树
TreeNode* buildTree(vector<pair<int, int>>& nodes, int index) {
    if (index == 0) return NULL;
    TreeNode* root = new TreeNode(index);
    int left = nodes[index - 1].first;
    int right = nodes[index - 1].second;
    root->left = buildTree(nodes, left);
    root->right = buildTree(nodes, right);
    return root;
}

// 计算二叉树深度
int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> nodes(n);
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].first >> nodes[i].second;
    }
    TreeNode* root = buildTree(nodes, 1);
    int depth = maxDepth(root);
    cout << depth << endl;
    return 0;
}