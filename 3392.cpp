#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int ans = n * m; // 初始化为最大可能涂色数

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            int cur = 0;
            // 计算白色区域涂色数
            for (int r = 0; r <= i; ++r) {
                for (int c = 0; c < m; ++c) {
                    if (v[r][c] != 'W') {
                        cur++;
                    }
                }
            }
            // 计算蓝色区域涂色数
            for (int r = i + 1; r <= j; ++r) {
                for (int c = 0; c < m; ++c) {
                    if (v[r][c] != 'B') {
                        cur++;
                    }
                }
            }
            // 计算红色区域涂色数
            for (int r = j + 1; r < n; ++r) {
                for (int c = 0; c < m; ++c) {
                    if (v[r][c] != 'R') {
                        cur++;
                    }
                }
            }
            ans = min(ans, cur);
        }
    }

    cout << ans << endl;

    return 0;
}