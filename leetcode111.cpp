class Solution {
public:
    // 主函数，调用递归辅助函数
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0; // 如果树为空，深度为0
        }
        return minDepthHelper(root, 1); // 从根节点开始，初始深度为1
    }

private:
    // 递归辅助函数
    int minDepthHelper(TreeNode* node, int mindepth) {
       
        if (node->left == nullptr && node->right == nullptr) {
            return mindepth; // 如果当前节点是叶子节点，返回当前深度
        }
        int leftDepth=INT_MAX;
        int rightDepth=INT_MAX;
        if(node->left)leftDepth = minDepthHelper(node->left, mindepth + 1);
        if(node->right) rightDepth = minDepthHelper(node->right, mindepth + 1);
       
        return min(leftDepth, rightDepth);
    }
};