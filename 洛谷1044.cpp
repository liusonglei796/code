#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    // dp数组用于存储不同个数元素操作下的输出序列总数
    long long dp[20];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;  // 当没有元素时，输出序列总数为1（其实就是一种空的情况）
    for (int i = 1; i <= n; ++i) {
        // 计算dp[i]，根据卡特兰数递推关系
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    cout << dp[n] << endl;
    return 0;
}