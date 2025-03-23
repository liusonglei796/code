#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> matrix;
vector<vector<bool>> visited;

// 四个方向的偏移量
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// 判断坐标是否在矩阵范围内
bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

// 深度优先搜索，标记闭合圈外的 0
void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny) && matrix[nx][ny] == 0 && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n;
    matrix.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n, false));

    // 读取矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // 从矩阵边界的 0 开始深度优先搜索，标记闭合圈外的 0
    for (int i = 0; i < n; ++i) {
        if (matrix[i][0] == 0 && !visited[i][0]) {
            dfs(i, 0);
        }
        if (matrix[i][n - 1] == 0 && !visited[i][n - 1]) {
            dfs(i, n - 1);
        }
        if (matrix[0][i] == 0 && !visited[0][i]) {
            dfs(0, i);
        }
        if (matrix[n - 1][i] == 0 && !visited[n - 1][i]) {
            dfs(n - 1, i);
        }
    }

    // 填涂闭合圈内的 0
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0 && !visited[i][j]) {
                matrix[i][j] = 2;
            }
        }
    }

    // 输出结果
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << (j == n - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}