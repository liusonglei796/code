#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305;
const int INF = 0x3f3f3f3f;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int burnt[MAXN][MAXN]; // 记录每个格子被烧焦的时间

struct Node {
    int x, y, t;
};

int main() {
    int m;
    cin >> m;
    
    // 初始化所有格子为无限大时间（表示永不被烧焦）
    memset(burnt, 0x3f, sizeof(burnt));
    
    // 读入流星信息
    for (int i = 0; i < m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        
        // 更新流星落点及周围四个格子的烧焦时间
        burnt[x][y] = min(burnt[x][y], t);
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx >= 0 && ny >= 0) {
                burnt[nx][ny] = min(burnt[nx][ny], t);
            }
        }
    }
    
    // BFS寻找最短路径
    queue<Node> q;
    q.push({0, 0, 0}); // 起点(0,0)，时间0
    
    bool visited[MAXN][MAXN] = {0};
    visited[0][0] = true;
    
    // 如果起点已经被烧焦，且时间为0，则无法移动
    if (burnt[0][0] <= 0) {
        cout << -1 << endl;
        return 0;
    }
    
    while (!q.empty()) {
        Node curr = q.front();
        q.pop();
        
        // 如果当前位置永远不会被烧焦，找到安全点
        if (burnt[curr.x][curr.y] == INF) {
            cout << curr.t << endl;
            return 0;
        }
        
        // 尝试四个方向移动
        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            int nt = curr.t + 1;
            
            // 检查是否越界、是否已访问、是否在流星到达前可以到达
            if (nx >= 0 && ny >= 0 && !visited[nx][ny] && nt < burnt[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny, nt});
            }
        }
    }
    
    // 如果无法到达安全点
    cout << -1 << endl;
    return 0;
}
