#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, x, y;
vector<vector<int>> v;

int main() {
    cin >> n >> m >> x >> y;
    v.resize(n + 1, vector<int>(m + 1, -1)); // 初始化为 -1 表示未访问

    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};  // 马的 8 种移动方式
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    queue<pair<int, int>> q;
    q.push({x, y});
    v[x][y] = 0;  // 起点步数为 0

    while (!q.empty()) {
        // 手动获取队列头部元素
        pair<int, int> current = q.front();
        int cx = current.first;
        int cy = current.second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && v[nx][ny] == -1) {
                v[nx][ny] = v[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
    // 输出结果
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}