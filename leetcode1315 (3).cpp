class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return dfs(root);
    }

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int sum = 0;

        // 检查当前节点的孙子节点
        if (node->val % 2 == 0) {
            if (node->left != nullptr) {
                if (node->left->left != nullptr) {
                    sum += node->left->left->val;
                }
                if (node->left->right != nullptr) {
                    sum += node->left->right->val;
                }
            }
            if (node->right != nullptr) {
                if (node->right->left != nullptr) {
                    sum += node->right->left->val;
                }
                if (node->right->right != nullptr) {
                    sum += node->right->right->val;
                }
            }
        }

        // 递归遍历左右子树，并将结果累加
        sum += dfs(node->left);
        sum += dfs(node->right);

        return sum;
    }
};