#include <iostream>
using namespace std;

// 快速乘法函数，计算 (a * b) % p
long long quick_mul(long long a, long long b, long long p) {
    long long ans = 0;
    a %= p;
    b %= p;
    while (b) {
        if (b & 1) {
            ans = (ans + a) % p;
        }
        a = (a + a) % p;
        b>>=1;
    }
    return ans;
}

int main() {
    long long a, b, p;
    cin >> a >> b >> p;  // 输入 a, b 和模数 p

    cout << quick_mul(a, b, p) << endl;  // 输出最终结果

    return 0;
}