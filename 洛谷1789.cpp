#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;  // n最大为100
bool light[MAXN][MAXN];  // 标记是否被照亮

// 火把的照明范围（根据题目给出的图案）
const int torch_dx[] = {0,  // 中心
                       -1,-1,-1,0,0,0,1,1,1,  // 3x3区域
                       -2,0,2,  // 上下额外的点
                       0,0};    // 左右额外的点
const int torch_dy[] = {0,  // 中心
                       -1,0,1,-1,0,1,-1,0,1,  // 3x3区域
                       0,2,0,  // 上下额外的点
                       -2,2};  // 左右额外的点

// 萤石的照明范围（5x5正方形）
const int stone_dx[] = {-2,-2,-2,-2,-2,
                       -1,-1,-1,-1,-1,
                       0,0,0,0,0,
                       1,1,1,1,1,
                       2,2,2,2,2};
const int stone_dy[] = {-2,-1,0,1,2,
                       -2,-1,0,1,2,
                       -2,-1,0,1,2,
                       -2,-1,0,1,2,
                       -2,-1,0,1,2};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    // 处理火把的照明
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        
        // 标记火把照亮的范围
        for(int j = 0; j < 14; j++) {  // 火把照亮14个点
            int nx = x + torch_dx[j];
            int ny = y + torch_dy[j];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                light[nx][ny] = true;
            }
        }
    }
    
    // 处理萤石的照明
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        
        // 标记萤石照亮的范围
        for(int j = 0; j < 25; j++) {  // 萤石照亮5x5=25个点
            int nx = x + stone_dx[j];
            int ny = y + stone_dy[j];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                light[nx][ny] = true;
            }
        }
    }
    
    // 统计未被照亮的格子数
    int dark = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!light[i][j]) dark++;
        }
    }
    
    cout << dark << endl;
    return 0;
}