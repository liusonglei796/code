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

// 深度优先搜索函数，用于生成组合并判断和是否为素数
void dfs(vector<int>& nums, int start, int k, int sum, int& count) {
    if (k == 0) {
        if (isPrime(sum)) {
            count++;
        }
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        dfs(nums, i + 1, k - 1, sum + nums[i], count);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int count = 0;
    dfs(nums, 0, k, 0, count);
    cout << count << endl;
    return 0;
}