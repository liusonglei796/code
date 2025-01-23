#include<bits/stdc++.h>
using namespace std;

int a[5000];  // 存储阶乘结果的数组

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, target;
        cin >> n >> target;
        
        // 初始化
        memset(a, 0, sizeof(a));
        a[1] = 1;  // 从1开始乘
        int len = 1;  // 当前数字的长度
        
        // 计算阶乘
        for(int i = 2; i <= n; i++) {
            int carry = 0;
            // 对每一位进行乘法运算
            for(int j = 1; j <= len; j++) {
                int temp = a[j] * i + carry;
                
                a[j] = temp % 10;
                carry = temp / 10;
            }
            // 处理剩余进位
            while(carry) {
                a[++len] = carry % 10;
                carry /= 10;
            }
        }
        
        // 统计目标数字出现次数
        int count = 0;
        for(int i = len; i >= 1; i--) {
            if(a[i] == target) count++;
        }
        
        cout << count << "\n";
    }
    return 0;
}