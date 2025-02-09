#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;  // 定义最大数组长度
long long n, m;            // n为树的数量，m为需要的木材长度
vector<long long> trees;   // 存储每棵树的高度

// 计算当前高度能得到的木材总长度
long long calc(long long height) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (trees[i] > height) {  // 只有树比切割高度高才能得到木材
            sum += trees[i] - height;
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);  // 优化输入输出
    cin.tie(nullptr);
    
    cin >> n >> m;
    trees.resize(n);  // 设置vector大小
    
    // 输入每棵树的高度
    long long maxH = 0;  // 记录最大高度
    for (int i = 0; i < n; i++) {
        cin >> trees[i];
        maxH = max(maxH, trees[i]);
    }
    
    // 二分查找最大高度
    long long left = 0, right = maxH;//只能从0开始从1开始会漏掉答案虽然 01都对
    long long ans = 0;  // 存储最终答案
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long wood = calc(mid);  // 计算当前高度能得到的木材长度
        
        if (wood == m) {  // 恰好相等，找到最优解
            ans = mid;
            break;
        } else if (wood > m) {  // 木材过多，尝试提高切割高度
            ans = mid;    // 记录当前可行的答案
            left = mid + 1;
        } else {          // 木材不够，需要降低切割高度
            right = mid - 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}