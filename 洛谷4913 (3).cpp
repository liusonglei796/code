#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定义二叉树节点
struct TreeNode {
    int left, right;
};

// 计算二叉树深度
void dfs(const vector<TreeNode>& tree, int pos, int currentDepth, int &maxDepth) {
    if (pos == 0) return; // 空节点直接返回

    // 更新最大深度
    maxDepth = max(maxDepth, currentDepth);

    // 递归遍历左子树和右子树
    dfs(tree, tree[pos].left, currentDepth + 1, maxDepth);
    dfs(tree, tree[pos].right, currentDepth + 1, maxDepth);
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

    int maxDepth = 0; // 初始化最大深度
    dfs(tree, 1, 1, maxDepth); // 从根节点开始遍历，初始深度为 1

    // 输出结果
    cout << maxDepth << endl;

    return 0;
}