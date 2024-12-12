class Solution {
public:
    int numColor(TreeNode* root) {
unordered_set<int>sk;
dfs(root,sk);
return sk.size();
    }
void dfs(TreeNode*node,unordered_set<int>&sk){
if(node==nullptr){return ;}
sk.insert(node->val);
dfs(node->left,sk);
dfs(node->right,sk);
}

};