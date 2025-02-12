class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true; // 空树是平衡的
        }
        return dfs(root) != -1; // 如果dfs返回-1，说明树不平衡
    }

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0; // 空节点的深度为0
        }
        int leftDepth = dfs(node->left); // 左子树的深度
        if (leftDepth == -1) {
            return -1; // 如果左子树不平衡，直接返回-1
        }
        int rightDepth = dfs(node->right); // 右子树的深度
        if (rightDepth == -1) {
            return -1; // 如果右子树不平衡，直接返回-1
        }
        if (abs(leftDepth - rightDepth) > 1) {
            return -1; // 如果左右子树深度差超过1，返回-1
        }
        return max(leftDepth, rightDepth) + 1; // 返回当前节点的深度
    }
};