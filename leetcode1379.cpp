class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr) {
            return nullptr;
        }
        if (original == target) {
            return cloned; // 如果原始树中的当前节点是目标节点，返回克隆树中的对应节点
        }
        // 递归在原始树和克隆树中查找目标节点
        TreeNode* leftResult = getTargetCopy(original->left, cloned->left, target);
        if (leftResult != nullptr) {
            return leftResult; // 如果在左子树中找到目标节点，直接返回
        }
        return getTargetCopy(original->right, cloned->right, target); // 否则在右子树中查找
    }
};