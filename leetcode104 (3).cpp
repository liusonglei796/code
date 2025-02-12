class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return dfs(root, 1);
    }

    int dfs(TreeNode* node, int currentDepth) {
        if (node->left == nullptr && node->right == nullptr) {
            return currentDepth; // 如果当前节点是叶子节点，返回当前深度
        }
        int left = 0; // 初始化左子树深度
        int right = 0; // 初始化右子树深度

        if (node->left) {
            left = dfs(node->left, currentDepth + 1); // 递归计算左子树的最大深度
        }
        if (node->right) {
            right = dfs(node->right, currentDepth + 1); // 递归计算右子树的最大深度
        }
        return max(left, right); // 返回左右子树中较大的深度
    }
};