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
    sum += step * t[pos].value;
    int fa = t[pos].father, l = t[pos].left, r = t[pos].right;
    
    if (fa &&!vis[fa]) {
        vis[fa] = true;
        dfs(step + 1, fa);
    
    }
    
    if (l &&!vis[l]) {
        vis[l] = true;
        dfs(step + 1, l);
    
    }
    
    if (r &&!vis[r]) {
        vis[r] = true;
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
        sum = 0;
        memset(vis, false, sizeof(vis));
        vis[i] = true;
        dfs(0, i);
        ans = min(ans, sum);
    }
    
    cout << ans << endl;
    
    return 0;
}