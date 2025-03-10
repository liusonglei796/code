#include <iostream>
#include <queue>
using namespace std;
 
const int N = 35;
int g[N][N], vis[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int n;
 
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x,  y});
    vis[x][y] = 1;
    
    while (!q.empty())  {
        auto [x, y] = q.front(); 
        q.pop(); 
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx <= n+1 && ny >= 0 && ny <= n+1 
                && !vis[nx][ny] && g[nx][ny] == 0) {
                vis[nx][ny] = 1;
                q.push({nx,  ny});
            }
        }
    }
}
 
int main() {
    cin >> n;
    // 扩展外围一圈0，简化边界判断 [2]()
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    
    bfs(0, 0); // 从外围虚拟起点开始搜索 
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] == 1) cout << 1;
            else cout << (vis[i][j] ? 0 : 2);
            if (j != n) cout << " ";
        }
        cout << endl;
    }
    return 0;
} 