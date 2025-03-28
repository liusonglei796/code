#include <bits/stdc++.h>
using namespace std;

// 胜负规则表
// result[a][b] 表示 a 对 b 的结果：1 表示 a 胜，-1 表示 b 胜，0 表示平局
const int result[5][5] = {
    {0, -1, 1, 1, -1}, // 剪刀（0）
    {1, 0, -1, 1, -1}, // 石头（1）
    {-1, 1, 0, -1, 1}, // 布（2）
    {-1, -1, 1, 0, 1}, // 蜥蜴人（3）
    {1, 1, -1, -1, 0}  // 斯波克（4）
};

int main() {
    int N, NA, NB;
    cin >> N >> NA >> NB;

    vector<int> A(NA), B(NB);
    for (int i = 0; i < NA; i++) cin >> A[i];
    for (int i = 0; i < NB; i++) cin >> B[i];

    int scoreA = 0, scoreB = 0;

    for (int i = 0; i < N; i++) {
        int a = A[i % NA]; // 小 A 的出拳
        int b = B[i % NB]; // 小 B 的出拳

        if (result[a][b] == 1) {
            scoreA++; // 小 A 胜
        } else if (result[a][b] == -1) {
            scoreB++; // 小 B 胜
        }
        // 平局不计分
    }

    cout << scoreA << " " << scoreB << endl;
    return 0;
}