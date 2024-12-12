class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr){return {};}
        vector<int>v;
        int depth=0;
        dfs(root,depth,v);
        return v;
    }
void dfs(TreeNode*node,int depth,vector<int>&v){
if(node==nullptr){return ;}
if(depth==v.size()){
    v.push_back(node->val);
}
dfs(node->right,depth+1,v);
dfs(node->left,depth+1,v);
}


};