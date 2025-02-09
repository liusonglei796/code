#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<long long> nums;  // 使用long long避免溢出

// 检查是否可以将数组分成m段，使得每段和不超过maxSum
bool check(long long maxSum) {
    int count = 1;  // 当前段数
    long long sum = 0;  // 当前段的和
    
    for(int i = 0; i < n; i++) {
        // 如果单个数大于maxSum，直接返回false
        if(nums[i] > maxSum) return false;
        
        // 如果加入当前数会超过maxSum，开始新的一段
        if(sum + nums[i] > maxSum) {
            count++;
            sum = nums[i];
        } else {
            sum += nums[i];
        }
    }
    
    return count <= m;  // 如果段数不超过m，返回true
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    nums.resize(n);
    
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }
    
    // 二分查找最小的maxSum
    long long left = 0;
    long long right = sum;
    long long ans = sum;
    
    while(left <= right) {
        long long mid = left + (right - left) / 2;
        if(check(mid)) {
            ans = mid;
            right = mid - 1;  // 尝试更小的值
        } else {
            left = mid + 1;   // 需要更大的值
        }
    }
    
    cout << ans << endl;
    return 0;
}