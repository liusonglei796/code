#include <iostream>
using namespace std;

// 计算两个数的最大公约数
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    long long x0, y0;
    cin >> x0 >> y0;
    
    // 如果 y0 不能被 x0 整除，直接返回 0
    if (y0 % x0 != 0) {
        cout << 0 << endl;
        return 0;
    }
    
    // m 是 a 和 b 的最小公倍数
    long long m = y0 / x0;
    int count = 0;
    
    // 枚举 m 的所有因数
    for (long long i = 1; i * i <= m; i++) {
        if (m % i == 0) {
            // 检查 (i, m/i) 是否互质
            if (gcd(i, m/i) == 1) {
                // 如果 i * i = m，只算一次
                if (i * i == m) {
                    count += 1;
                } 
                // 否则算两个对：(i, m/i) 和 (m/i, i)
                else {
                    count += 2;
                }
            }
        }
    }
    
    cout << count << endl;
    return 0;
}