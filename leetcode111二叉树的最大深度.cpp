class Solution {
public:
  int minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    // 如果左子树为空，那么整棵树的最小深度取决于右子树
    if (root->left == nullptr) {
        return right + 1;
    }
    // 如果右子树为空，那么整棵树的最小深度取决于左子树
    if (root->right == nullptr) {
        return left + 1;
    }
    // 左右子树都不为空时，取左右子树最小深度的较小值加1
    return std::min(left, right) + 1;
}
};