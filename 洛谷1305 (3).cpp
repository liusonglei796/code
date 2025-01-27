#include <iostream>
#include <vector>
using namespace std;

typedef struct TreeNode {
    char l;
    char r;
} TreeNode;

vector<TreeNode> v(128); // 使用 ASCII 码作为索引，大小为 128

void dfs(char a) {
    if (a == '*') { // 如果当前节点为空，直接返回
        return;
    }
    cout << a; // 输出当前节点
    dfs(v[a].l); // 递归遍历左子树
    dfs(v[a].r); // 递归遍历右子树
}

int main() {
    int n;
    cin >> n;
    char root;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (i == 0) { // 第一行输入的是根节点
            root = s[0];
        }
        v[s[0]].l = s[1]; // 左子节点
        v[s[0]].r = s[2]; // 右子节点
    }
    dfs(root); // 从根节点开始前序遍历
    return 0;
}