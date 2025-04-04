#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    
    // 方向向量：右、下、左、上
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dir = 0; // 初始方向向右
    
    int x = 0, y = 0; // 当前位置
    int num = 1;
    
    while (num <= n * n) {
        matrix[x][y] = num++;
        
        // 计算下一个位置
        int nx = x + dirs[dir][0];
        int ny = y + dirs[dir][1];
        
        // 如果下一个位置超出边界或者已经填过，则需要转向
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || matrix[nx][ny] != 0) {
            dir = (dir + 1) % 4; // 顺时针转向
            nx = x + dirs[dir][0];
            ny = y + dirs[dir][1];
        }
        
        x = nx;
        y = ny;
    }
    
    // 输出矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
    
    return 0;
}