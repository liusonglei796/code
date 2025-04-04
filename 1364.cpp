#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

const int MAXN = 105;

// 定义节点结构体
struct Node {
    int left, right, father, value;
} t[MAXN];
int n, sum, ans = INT_MAX;
bool vis[MAXN];
// 深度优先搜索函数
void dfs(int step, int pos) {
if(pos==0||vis[pos])return ;

    if (!vis[pos]) { // 如果当前节点未被访问
        sum += step * t[pos].value; // 累加当前节点的贡献
        vis[pos] = true; // 标记为已访问
    }

    int fa = t[pos].father, l = t[pos].left, r = t[pos].right;

    // 递归访问父节点
    if (!vis[fa]) {
        dfs(step + 1, fa);
    }

    // 递归访问左子节点
    if (!vis[l]) {
        dfs(step + 1, l);
    }

    // 递归访问右子节点
    if ( !vis[r]) {
        dfs(step + 1, r);
    }
}

int main() {
    cin >> n;

    // 输入节点信息
    for (int i = 1; i <= n; i++) {
        cin >> t[i].value >> t[i].left >> t[i].right;
        if (t[i].left) t[t[i].left].father = i;
        if (t[i].right) t[t[i].right].father = i;
    }

    // 遍历每个节点作为医院的位置
    for (int i = 1; i <= n; i++) {
        sum = 0; // 重置总距离和
        memset(vis, false, sizeof(vis)); // 重置访问状态
        dfs(0, i); // 从当前节点开始 DFS
        ans = min(ans, sum); // 更新最小距离和
    }

    cout << ans << endl;

    return 0;
}