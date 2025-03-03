#include <iostream>
#include <cstring>
#include <string>
#include <climits>

using namespace std;

const int N = 5;

void toggle(char grid[N][N], int x, int y) {
    grid[x][y] ^= 1; // '0'和'1'的ASCII码为48和49，异或1即可翻转
    if (x > 0) grid[x-1][y] ^= 1;
    if (x < N-1) grid[x+1][y] ^= 1;
    if (y > 0) grid[x][y-1] ^= 1;
    if (y < N-1) grid[x][y+1] ^= 1;
}

int solve(char original[N][N]) {
    int min_steps = INT_MAX;

    for (int mask = 0; mask < 32; ++mask) {
        char temp[N][N];
        memcpy(temp, original, sizeof(temp));
        int steps = 0;

        // 处理第一行的按法
        for (int j = 0; j < N; ++j) {
            if (mask & (1 << j)) {
                toggle(temp, 0, j);
                ++steps;
                if (steps > 6) break;
            }
        }
        if (steps > 6) continue;

        // 处理剩余行
        for (int i = 0; i < N-1; ++i) {
            for (int j = 0; j < N; ++j) {
                if (temp[i][j] == '0') {
                    toggle(temp, i+1, j);
                    ++steps;
                    if (steps > 6) break;
                }
            }
            if (steps > 6) break;
        }

        if (steps > 6) continue;

        // 检查最后一行是否全亮
        bool all_on = true;
        for (int j = 0; j < N; ++j) {
            if (temp[N-1][j] != '1') {
                all_on = false;
                break;
            }
        }
        if (all_on && steps < min_steps) {
            min_steps = steps;
        }
    }

    return (min_steps <= 6) ? min_steps : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore(); // 忽略可能的换行符

    while (n--) {
        char grid[N][N];
        int row = 0;
        string line;

        while (row < N) {
            getline(cin, line);
            if (line.empty()) continue; // 跳过空行
            for (int j = 0; j < N; ++j) {
                grid[row][j] = line[j];
            }
            ++row;
        }

        cout << solve(grid) << '\n';
    }

    return 0;
}