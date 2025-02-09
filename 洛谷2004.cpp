#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, C;
    cin >> N >> M >> C;

    // 读取地图数据
    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }

    // 计算二维前缀和
    vector<vector<int>> prefixSum(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + map[i - 1][j - 1];
        }
    }

    // 初始化最大土地价值和及其对应的左上角坐标
    int maxValue = -1e9;
    int maxX = 0, maxY = 0;

    // 枚举所有可能的首都左上角坐标
    for (int i = 0; i <= N - C; ++i) {
        for (int j = 0; j <= M - C; ++j) {
            // 计算以 (i, j) 为左上角的 C * C 正方形的土地价值和
            int value = prefixSum[i + C][j + C] - prefixSum[i][j + C] - prefixSum[i + C][j] + prefixSum[i][j];
            if (value > maxValue) {
                maxValue = value;
                maxX = i;
                maxY = j;
            }
        }
    }

    // 输出结果
    cout << maxX + 1 << " " << maxY + 1 << endl;

    return 0;
}
