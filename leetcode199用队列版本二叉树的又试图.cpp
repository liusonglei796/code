class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
    if (root == nullptr) return result;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            // 每层的最右边的节点
            if (i == size - 1) result.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return result;
    }
};