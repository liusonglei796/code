#include <iostream>
#include <vector>
using namespace std;

typedef struct TreeNode {
    char l;
    char r;
} TreeNode;

vector<TreeNode> v(26); // 使用大小为 26 的 vector

void dfs(char a) {
    if (a == '*') {
        return;
    }
    cout << a;
    dfs(v[a - 'a'].l); // 使用 字母 - 'a' 作为索引
    dfs(v[a - 'a'].r); // 使用 字母 - 'a' 作为索引
}

int main() {
    int n;
    cin >> n;
    char root;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (i == 0) {
            root = s[0];
        }
        v[s[0] - 'a'].l = s[1]; // 使用 字母 - 'a' 作为索引
        v[s[0] - 'a'].r = s[2]; // 使用 字母 - 'a' 作为索引
    }
    dfs(root);
    return 0;
}