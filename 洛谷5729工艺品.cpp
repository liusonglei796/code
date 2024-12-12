#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int w, x, h, q;
    cin >> w >> x >> h >> q;
    // 三维数组用于标记每个小方块是否被切割，初始化为0表示未被切割
    bool a[21][21][21] = {false};
    for (int i = 0; i < q; ++i) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        // 根据输入的坐标范围，将对应小方块标记为已切割（true）
        for (int ii = x1; ii <= x2; ii++) {
            for (int jj = y1; jj <= y2; jj++) {
                for (int kk = z1; kk <= z2; kk++) {
                    a[ii][jj][kk] = true;
                }
            }
        }
    }
    int remaining = 0;
    // 遍历整个三维空间，统计未被切割的小方块数量
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k <= h; k++) {
                if (!a[i][j][k]) {
                    remaining++;
                }
            }
        }
    }
    cout << remaining << endl;
    return 0;
}