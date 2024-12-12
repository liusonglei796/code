class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root==nullptr){return 0;}
int sum=0;
int prefix=0;
dfs(root,prefix,sum);
return sum;
    }
void dfs(TreeNode*node,int prefix,int &sum){
if(node==nullptr){return ;}
prefix=prefix*10+node->val;
if(node->left==nullptr&&node->right==nullptr){
    sum+=prefix;
}
dfs(node->right,prefix,sum);
dfs(node->left,prefix,sum);
}

};