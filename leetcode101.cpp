class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true; // 空树是对称的
        }
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode* node1, TreeNode* node2) {
        // 如果两个节点都为空，说明这部分是对称的
        if (node1 == nullptr && node2 == nullptr) {
            return true;
        }
        // 如果一个为空，另一个不为空，说明不对称
        if (node1 == nullptr || node2 == nullptr) {
            return false;
        }
        // 如果两个节点的值不相等，说明不对称
        if (node1->val != node2->val) {
            return false;
        }
        // 递归检查左子树的左节点与右子树的右节点，以及左子树的右节点与右子树的左节点
        return dfs(node1->left, node2->right) && dfs(node1->right, node2->left);
    }
};