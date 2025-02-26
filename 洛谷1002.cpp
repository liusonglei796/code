#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 25;
ll dp[MAXN][MAXN];  // dp数组存储到达每个点的路径数
bool horse[MAXN][MAXN];  // 标记马的控制点

// 马能够攻击到的8个位置的偏移量
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main(){
    int n, m, hx, hy;
    cin >> n >> m >> hx >> hy;
    
    // 标记马的位置和控制点
    horse[hx][hy] = true;
    for(int i = 0; i < 8; i++) {
        int nx = hx + dx[i];
        int ny = hy + dy[i];
        if(nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
            horse[nx][ny] = true;
        }
    }
    
    // 初始化起点
    dp[0][0] = horse[0][0] ? 0 : 1;
    
    // 动态规划
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(horse[i][j]) continue;  // 跳过马的控制点
            if(i > 0) dp[i][j] += dp[i-1][j];  // 从上方来
            if(j > 0) dp[i][j] += dp[i][j-1];  // 从左方来
        }
    }
    
    cout << dp[n][m] << endl;
    return 0;
}