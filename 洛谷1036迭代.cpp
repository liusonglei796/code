#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 判断一个数是否为质数（素数）
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int count = 0;
    // 利用位运算枚举所有可能的组合情况
    for (int comb = 0; comb < (1 << n); comb++) {  // 从0到2^n - 1，每个二进制表示一种选取情况
        int sum = 0;
        int selectedCount = 0;
        for (int i = 0; i < n; i++) {
            if (comb & (1 << i)) {  // 判断第i个数是否在当前组合中
                sum += nums[i];
                selectedCount++;
            }
        }
        if (selectedCount == k && isPrime(sum)) {  // 满足选取k个数且和为素数的情况
            count++;
        }
    }

    cout << count << endl;
    return 0;
}