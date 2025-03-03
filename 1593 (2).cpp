#include <bits/stdc++.h>
using namespace std;

const int N = 5;
int grid[N][N], temp[N][N];
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};

// 按下(x,y)位置的开关
void press(int x, int y) {
    for (int i = 0; i < 5; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            temp[nx][ny] ^= 1; // 翻转状态
        }
    }
}

// 检查是否所有灯都亮了
bool check() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (temp[i][j] == 0) return false;
        }
    }
    return true;
}

int solve() {
    int ans = 7; // 初始化为大于6的值
    
    // 枚举第一行的所有按法
    for (int state = 0; state < (1 << N); state++) {
        // 复制原始状态到临时数组
        memcpy(temp, grid, sizeof(grid));
        
        int steps = 0;
        
        // 处理第一行的按法
        for (int j = 0; j < N; j++) {
            if ((state >> j) & 1) {
                press(0, j);
                steps++;
            }
        }
        
        // 根据当前行的状态决定下一行的按法
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (temp[i-1][j] == 0) {
                    press(i, j);
                    steps++;
                }
            }
        }
        
        // 检查最后一行是否全亮
        bool valid = true;
        for (int j = 0; j < N; j++) {
            if (temp[N-1][j] == 0) {
                valid = false;
                break;
            }
        }
        
        if (valid && steps <= 6) {
            ans = min(ans, steps);
        }
    }
    
    return ans <= 6 ? ans : -1;
}

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        // 读取游戏初始状态
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < N; j++) {
                grid[i][j] = s[j] - '0';
            }
        }
        
        cout << solve() << endl;
    }
    
    return 0;
}