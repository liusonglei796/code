class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr||root2==nullptr){
            return false;
        }
        if(root1==nullptr&&root2==nullptr){
            return true;
        }
  stack<TreeNode*>s1,s2;
        s1.push(root1);
        s2.push(root2);
 //如果一个栈为空另一个栈不为空说明树的叶结点数量不相等所以停止循环直接return
while(!s1.empty()&&!s2.empty()){
TreeNode*node1=s1.top();s1.pop();
TreeNode*node2=s2.top();s2.pop();
while(node1->left||node1->right){
    if(node1->left){
        if(node1->right)s1.push(node1->right);
        node1=node1->left;
    }else{
        node1=node1->right;
    }
}
//只要是双亲结点就进行循环直到到叶子结点
while(node2->left||node2->right){
    //从左往右进行：
    //有两个孩子
    if(node2->left){
        if(node2->right)s2.push(node2->right);
        node2=node2->left;
    }//只有一个孩子
    else{
        node2=node2->right;
    }
}
if(node1->val!=node2->val)return false;
}
 //如果一个栈为空另一个栈不为空说明树的叶结点数量不相等是fasle如果两个都为空而且前面已经判断值相等
 //如果有一个值不相等会返回false；不会执行到此
return s1.empty()&&s2.empty();

}

    
};