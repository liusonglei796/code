#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    vector<int> a(n + 2, 0); // 学生成绩，1-based
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // 差分数组
    vector<int> diff(n + 2, 0);

    // 处理每个操作
    for (int i = 0; i < p; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        diff[x] += z;
        if (y + 1 <= n) {
            diff[y + 1] -= z;
        }
    }

    // 计算最终成绩并找到最低分
    int min_score = INT_MAX;
    int current = 0;
    for (int i = 1; i <= n; ++i) {
        current += diff[i];
        a[i] += current;
        if (a[i] < min_score) {
            min_score = a[i];
        }
    }

    cout << min_score << endl;

    return 0;
}