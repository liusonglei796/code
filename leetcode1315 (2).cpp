class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int sum = 0;
        dfs(root, sum);
        return sum;
    }

    void dfs(TreeNode* node, int &sum) {
        if (node == nullptr) {
            return;
        }

        // 检查当前节点的孙子节点
        if (node->left != nullptr) {
            if (node->left->left != nullptr && node->val % 2 == 0) {
                sum += node->left->left->val;
            }
            if (node->left->right != nullptr && node->val % 2 == 0) {
                sum += node->left->right->val;
            }
        }

        if (node->right != nullptr) {
            if (node->right->left != nullptr && node->val % 2 == 0) {
                sum += node->right->left->val;
            }
            if (node->right->right != nullptr && node->val % 2 == 0) {
                sum += node->right->right->val;
            }
        }

        // 递归遍历左右子树
        dfs(node->left, sum);
        dfs(node->right, sum);
    }
};