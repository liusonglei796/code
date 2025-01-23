#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定义二叉树节点
struct TreeNode {
    int left, right;
};

// 计算二叉树深度
int calculateDepth(const vector<TreeNode>& tree, int node) {
    if (node == 0) return 0;  // 空节点深度为 0
    int leftDepth = calculateDepth(tree, tree[node].left);  // 左子树深度
    int rightDepth = calculateDepth(tree, tree[node].right); // 右子树深度
    return max(leftDepth, rightDepth) + 1;  // 当前节点深度为左右子树深度的最大值加 1
}

int main() {
    int n;
    cin >> n;

    // 存储每个节点的左右子节点编号
    vector<TreeNode> tree(n + 1);  // 节点编号从 1 开始

    // 输入每个节点的左右子节点
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].left >> tree[i].right;
    }

    // 计算二叉树的深度
    int depth = calculateDepth(tree, 1);

    // 输出结果
    cout << depth << endl;

    return 0;
}