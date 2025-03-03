#include<bits/stdc++.h>
using namespace std;

const int MOD = 9901;

// 快速幂，计算 (a^b) % MOD
int qpow(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = (1LL * res * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return res;
}

// 计算 (1 + p + p^2 + ... + p^k) % MOD
int sum(int p, int k) {
    // 当 p % MOD == 1 时，直接返回 (k+1) % MOD
    if (p % MOD == 1) {
        return (k + 1) % MOD;
    }
    
    // 使用等比数列求和公式: (p^(k+1) - 1) / (p - 1)
    int numerator = (qpow(p, k + 1) - 1 + MOD) % MOD;
    int denominator = qpow(p - 1, MOD - 2); // 费马小定理求逆元
    return 1LL * numerator * denominator % MOD;
}

// 当 p-1 能被 MOD 整除时的特殊处理
int sum_special(int p, int k) {
    return (1LL * (k + 1) * qpow(p, k)) % MOD;
}

int main() {
    int a, b;
    cin >> a >> b;
    
    if (a == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    if (b == 0) {
        cout << 1 << endl;
        return 0;
    }
    
    // 质因数分解
    int ans = 1;
    for (int i = 2; 1LL * i * i <= a; i++) {
        if (a % i == 0) {
            int cnt = 0;
            while (a % i == 0) {
                cnt++;
                a /= i;
            }
            
            // 计算 1 + i + i^2 + ... + i^(cnt*b)
            int exp = 1LL * cnt * b % (MOD - 1); // 由费马小定理，指数对 MOD-1 取模
            int factor_sum = sum(i, exp);
            
            ans = 1LL * ans * factor_sum % MOD;
        }
    }
    
    // 处理剩余的质因子（如果a还不为1）
    if (a > 1) {
        int exp = 1LL * b % (MOD - 1);
        int factor_sum = sum(a, exp);
        ans = 1LL * ans * factor_sum % MOD;
    }
    
    cout << ans << endl;
    return 0;
}