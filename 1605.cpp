#include <iostream>
#include <vector>
using namespace std;

int n, m, t;
int sx, sy, fx, fy;
vector<vector<bool>> v;
vector<vector<bool>> visited;  // 用于标记已经访问过的点
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int cnt = 0;

void dfs(int x, int y) {
    if (x == fx && y == fy) {
        cnt++;
        return;
    }
    // 标记当前点为已访问
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        // 检查新位置是否合法且未访问过，同时不是障碍物
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny] && !v[nx][ny]) {
            dfs(nx, ny);
        }
    }
    // 回溯，将当前点标记为未访问
    visited[x][y] = false;
}

int main() {
    cin >> n >> m >> t;
    v.resize(n + 1, vector<bool>(m + 1, false));
    visited.resize(n + 1, vector<bool>(m + 1, false));
    cin >> sx >> sy >> fx >> fy;
    for (int i = 0; i < t; ++i) {
        int x, y;
        cin >> x >> y;
        v[x][y] = true;  // 标记障碍物
    }
    dfs(sx, sy);
    cout << cnt;
    return 0;
}