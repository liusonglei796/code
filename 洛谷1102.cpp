#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, C;
    cin >> N >> C;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    // 统计每个数的频率
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    long long result = 0;
    for (int num : nums) {
        int target = num - C; // 计算 B = A - C
        if (freq.count(target)) { // 如果 B 存在
            result += freq[target]; // 累加 B 的出现次数
        }
    }

    cout << result << endl;
    return 0;
}