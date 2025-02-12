class Solution {
public:
bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    // 如果两个节点都为空，返回 true
    if (!root1 && !root2) {
        return true;
    }
    // 如果一个为空而另一个不为空，或者两个节点的值不相等，返回 false
    if (!root1 || !root2 || root1->val != root2->val) {
        return false;
    }
    // 递归检查两种情况：
    // 1. 左子树和右子树分别翻转等价
    // 2. 左子树和右子树分别交换后翻转等价
    return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
           (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
}
};