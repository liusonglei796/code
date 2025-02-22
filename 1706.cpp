#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> path;      // 改名为path更直观
vector<bool> visited;  // 改名为visited更符合惯例

void dfs(int pos) {
     if (pos == n) {
        for (int i = 0; i < n; i++) {
            cout << setw(5) << path[i];  // 使用setw控制场宽
        }
        cout << '\n';
        return;
    }
    
    // 尝试放置每个数字
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            path[pos] = i;
            dfs(pos + 1);
            visited[i] = false;  // 回溯，恢复状态
        }
    }
}

int main() {
    cin >> n;
    path.resize(n);
    visited.resize(n + 1, false);  // 初始化为false更明确
    dfs(0);
    return 0;
}