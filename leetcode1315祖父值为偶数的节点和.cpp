class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        if (root == nullptr) return 0;
        int sum = 0;
        dfs(root, sum);
        return sum;
    }

private:
    void dfs(TreeNode* node, int& sum) {
        if (node == nullptr) return;
        // 检查左子节点的左子节点
        if (node->left!= nullptr && node->left->left!= nullptr && node->val % 2 == 0) {
            sum += node->left->left->val;
        }
        // 检查左子节点的右子节点
        if (node->left!= nullptr && node->left->right!= nullptr && node->val % 2 == 0) {
            sum += node->left->right->val;
        }
        // 检查右子节点的左子节点
        if (node->right!= nullptr && node->right->left!= nullptr && node->val % 2 == 0) {
            sum += node->right->left->val;
        }
        // 检查右子节点的右子节点
        if (node->right!= nullptr && node->right->right!= nullptr && node->val % 2 == 0) {
            sum += node->right->right->val;
        }
        dfs(node->left, sum);
        dfs(node->right, sum);
    }
};
