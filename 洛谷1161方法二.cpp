#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> flipCount; // 记录每个路灯的翻转次数

    for (int i = 0; i < n; ++i) {
        double a;
        int t;
        cin >> a >> t;
        for (int j = 1; j <= t; ++j) {
            int lamp = floor(a * j);
            flipCount[lamp]++; // 更新翻转次数
        }
    }

    // 找到翻转次数为奇数的路灯
    for (const auto& pair : flipCount) {
        if (pair.second % 2 == 1) {
            cout << pair.first << endl;
            return 0;
        }
    }

    return 0;
}