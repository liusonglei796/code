
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
private:
    int dfs(TreeNode* node, int prevSum) {
        if (node == nullptr) {
            return 0;
        }
        int currentSum = prevSum * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            return currentSum;
        }
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};