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

    queue<int> queueA, queueB;

    // 读取小 A 的出拳规律并存入队列
    for (int i = 0; i < NA; i++) {
        int x;
        cin >> x;
        queueA.push(x);
    }

    // 读取小 B 的出拳规律并存入队列
    for (int i = 0; i < NB; i++) {
        int x;
        cin >> x;
        queueB.push(x);
    }

    int scoreA = 0, scoreB = 0;

    for (int i = 0; i < N; i++) {
        int a = queueA.front(); // 小 A 的出拳
        int b = queueB.front(); // 小 B 的出拳

        // 判断胜负并更新得分
        if (result[a][b] == 1) {
            scoreA++; // 小 A 胜
        } else if (result[a][b] == -1) {
            scoreB++; // 小 B 胜
        }

        // 将出拳重新放回队尾
        queueA.push(queueA.front());
        queueA.pop();
        queueB.push(queueB.front());
        queueB.pop();
    }

    cout << scoreA << " " << scoreB << endl;
    return 0;
}