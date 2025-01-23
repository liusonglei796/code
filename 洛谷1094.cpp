#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int w, n;  // w: 每组价格上限, n: 纪念品数量
    cin >> w >> n;
    
    vector<int> prices(n);
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    
    // 对价格排序以便使用双指针
    sort(prices.begin(), prices.end());
    
    int groups = 0;  // 记录组数
    int left = 0, right = n - 1;  // 双指针
    
    while(left <= right) {
        if(left == right) {  // 只剩一个纪念品
            groups++;
            break;
        }
        if(prices[left] + prices[right] <= w) {  // 可以组成一组
            left++;
            right--;
            groups++;
        } else {  // 价格最高的需要单独一组
            right--;
            groups++;
        }
    }
    
    cout << groups << "\n";
    return 0;
}