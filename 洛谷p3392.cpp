#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 50 + 5;
const int MAXM = 50 + 5;
char board[MAXN][MAXM];  // 存储棋盘原始状态

// 计算将从startRow到endRow行涂成目标颜色target需要涂染的格子数
int countPaint(int startRow, int endRow, char target, int n, int m) {
    int count = 0;
    for (int i = startRow; i <= endRow; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j]!= target) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    int minPaint = n * m;  // 初始化为最大可能值
    for (int whiteEnd = 0; whiteEnd < n - 2; whiteEnd++) {  // 白色条纹结束行
        for (int blueEnd = whiteEnd + 1; blueEnd < n - 1; blueEnd++) {  // 蓝色条纹结束行
            int whitePaint = countPaint(0, whiteEnd, 'W', n, m);
            int bluePaint = countPaint(whiteEnd + 1, blueEnd, 'B', n, m);
            int redPaint = countPaint(blueEnd + 1, n - 1, 'R', n, m);
            int totalPaint = whitePaint + bluePaint + redPaint;
            minPaint = min(minPaint, totalPaint);
        }
    }
    cout << minPaint << endl;
    return 0;
}