#include <iostream>
using namespace std;

long long fast(long long a, long long b, long long p) {
    long long result = 1;
    a = a % p;  // 初始对 a 取模
    while (b > 0) {
        //按位与运算符 & 是一个二元运算符，用于对两个操作数的对应二进制位进行逐位比较
        //判断奇偶性：在整数的二进制表示中，奇数的最低位是 1，偶数的最低位是 0。
        if (b & 1) {  // 使用位运算更高效
            result = (result * a) % p;
        }
        b >>= 1;  // 使用位运算右移
        a = (a * a) % p;
    }
    return result;
}

int main() {
    long long a, b, p;
    cin >> a >> b >> p;
    cout << a << "^" << b << " mod " << p << "=" << fast(a, b, p);
    return 0;
}