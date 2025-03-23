#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> path(n);
    for (int i = 0; i < n; ++i) {
        cin >> path[i];
    }

    // 找到给定排列的第 m 个后续排列
    for (int i = 0; i < m; ++i) {
        next_permutation(path.begin(), path.end());
    }

    // 输出结果
    for (int i = 0; i < n; ++i) {
        cout << path[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}