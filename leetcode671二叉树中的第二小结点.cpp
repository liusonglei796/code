class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (root == nullptr) return -1;
        return dfs(root, root->val);
    }

private:
    int dfs(TreeNode* node, int rootVal) {
        if (node == nullptr) return -1;
        if (node->val > rootVal) return node->val;
        int left = dfs(node->left, rootVal);
        int right = dfs(node->right, rootVal);
        if (left == -1) return right;
        if (right == -1) return left;
        return std::min(left, right);
    }
};