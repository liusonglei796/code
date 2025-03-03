#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5010;
int grid[MAXN][MAXN] = {0};  // 存储每个坐标的价值
int sum[MAXN][MAXN] = {0};   // 二维前缀和

int main() {
    int n, m;
    cin >> n >> m;
    
    // 读取目标信息
    int max_x = 0, max_y = 0;
    for (int i = 0; i < n; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        grid[x][y] += v;  // 累加同一位置的价值
        max_x = max(max_x, x);
        max_y = max(max_y, y);
    }
    
    // 计算二维前缀和
    for (int i = 0; i <= max_x; i++) {
        for (int j = 0; j <= max_y; j++) {
            sum[i+1][j+1] = grid[i][j] + sum[i][j+1] + sum[i+1][j] - sum[i][j];
        }
    }
    
    // 枚举所有可能的正方形左上角位置，寻找最大价值
    int max_value = 0;
    for (int i = 1; i <= max_x + 1; i++) {
        for (int j = 1; j <= max_y + 1; j++) {
            // 计算以(i,j)为左上角，边长为m的正方形内的总价值
            int r = min(i + m - 1, max_x + 1);
            int c = min(j + m - 1, max_y + 1);
            int value = sum[r][c] - sum[r][j-1] - sum[i-1][c] + sum[i-1][j-1];
            max_value = max(max_value, value);
        }
    }
    
    cout << max_value << endl;
    return 0;
}