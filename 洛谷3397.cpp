#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> diff(n + 2, vector<int>(n + 2, 0)); // 差分数组

    for (int k = 0; k < m; ++k) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 应用差分操作
        diff[x1][y1]++;
        diff[x1][y2 + 1]--;
        diff[x2 + 1][y1]--;
        diff[x2 + 1][y2 + 1]++;
    }

    // 计算二维前缀和
    vector<vector<int>> res(n + 2, vector<int>(n + 2, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            res[i][j] = res[i-1][j] + res[i][j-1] - res[i-1][j-1] + diff[i][j];
        }
    }

    // 输出结果
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << res[i][j] << (j == n ? "\n" : " ");
        }
    }

    return 0;
}