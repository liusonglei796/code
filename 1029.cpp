#include <iostream>
#include <cmath>

// 计算最大公约数(GCD)
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 计算最小公倍数(LCM)
long long lcm(int a, int b) {
    return (long long)a * b / gcd(a, b);
}

int main() {
    int x0, y0;
    std::cin >> x0 >> y0;  // 输入最大公约数和最小公倍数
    
    int count = 0;  // 记录满足条件的(P,Q)对数
    long long product = (long long)x0 * y0;  // x0和y0的乘积
    
    // 枚举所有可能的P
    // P必须是x0的倍数，且能被y0整除
    for (int i = 1; i <= sqrt(product); i++) {
        // 如果product不能被i整除，跳过
        if (product % i != 0) continue;
        
        int P = i;
        int Q = product / i;  // Q = (x0 * y0) / P
        
        // 检查这对(P,Q)是否满足条件：
        // 1. GCD(P,Q) = x0
        // 2. LCM(P,Q) = y0
        if (gcd(P, Q) == x0 && lcm(P, Q) == y0) {
            count += (P == Q) ? 1 : 2;  // 如果P=Q只计数一次，否则计数两次
        }
    }
    
    std::cout << count << std::endl;
    return 0;
}