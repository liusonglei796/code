#include <bits/stdc++.h>
using namespace std;

const int MAXN = 21;
long long dp[MAXN][MAXN];  // dp[i][j]表示从(0,0)到(i,j)的路径数
bool horse[MAXN][MAXN];    // 标记马的控制点

// 马能够到达的8个位置的偏移量
const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, hx, hy;
    cin >> n >> m >> hx >> hy;
    
    // 标记马的位置
    horse[hx][hy] = true;
    
    // 标记马能控制的位置
    for(int i = 0; i < 8; i++) {
        int nx = hx + dx[i];
        int ny = hy + dy[i];
        if(nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
            horse[nx][ny] = true;
        }
    }
    
    // 初始化起点
    dp[0][0] = horse[0][0] ? 0 : 1;
    
    // 初始化第一行和第一列
    for(int i = 1; i <= n; i++) {
        dp[i][0] = horse[i][0] ? 0 : dp[i-1][0];
    }
    for(int j = 1; j <= m; j++) {
        dp[0][j] = horse[0][j] ? 0 : dp[0][j-1];
    }
    
    // 动态规划
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(!horse[i][j]) {  // 如果不是马的控制点
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            // 如果是马的控制点，dp[i][j]保持为0
        }
    }
    
    cout << dp[n][m] << endl;
    return 0;
}