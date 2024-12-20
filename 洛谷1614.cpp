#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
 

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int minval = numeric_limits<int>::max();
    for (int i = 0; i <= n - m; ++i) {  // 修正外层循环范围，确保不会超出有效范围求子序列和
        int sum = 0;
        for (int j = i; j < i + m; ++j) {  // 修正内层循环范围，准确获取长度为m的子序列元素求和
            sum += v[j];
        }
        minval = min(sum, minval);
    }
    cout << minval << endl;
    return 0;
}