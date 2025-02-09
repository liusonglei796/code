#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v(3005);  // n最大为3000

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    // 输入n个刺痛值，从索引1开始存储
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    // 寻找连续m个数的最小和
    int minSum = INT_MAX;
    for(int i = 1; i <= n-m+1; i++) {  // 注意这里是n-m+1
        int sum = 0;
        // 计算从i开始的m个数的和
        for(int j = i; j <= i+m-1; j++) {  // 注意这里是i+m-1
            sum += v[j];
        }
        minSum = min(minSum, sum);
    }
    
    cout << minSum << endl;
    return 0;
}