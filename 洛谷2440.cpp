#include <iostream>
using namespace std;

// 定义数组最大长度
const int MAXN = 1000005;
// 存储每个物品的长度
long long a[MAXN];
// 物品的数量
long long n;
// 需要分割成的段数
long long k;

// 判断以长度 x 进行分割，能否得到至少 k 段
bool canCut(long long x) {
    // 初始化分割后的总段数为 0
    long long totalSegments = 0;
    // 遍历每个物品
    for (int i = 0; i < n; ++i) {
        // 计算当前物品按长度 x 分割能得到的段数，并累加到总段数中
        totalSegments += a[i] / x;
    }
    // 判断总段数是否大于等于 k
    return totalSegments >= k;
}

int main() {
    // 输入物品的数量和需要分割成的段数
    cin >> n >> k;
    // 输入每个物品的长度
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 二分查找的左边界，初始为 1（因为段长至少为 1）
    long long left = 1;
    // 二分查找的右边界，初始为一个较大的值，这里可以根据实际情况调整
    long long right = 1e9 + 1;
    // 存储最终结果
    long long result = 0;

    // 二分查找过程
    while (left <= right) {
        // 计算中间值
        long long mid = left + (right - left) / 2;
        if (canCut(mid)) {
            // 如果以 mid 为段长能满足条件，更新结果并尝试更大的段长
            result = mid;
            left = mid + 1;
        } else {
            // 否则，尝试更小的段长
            right = mid - 1;
        }
    }

    // 输出结果
    cout << result << endl;

    return 0;
}