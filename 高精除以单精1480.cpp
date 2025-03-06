#include <bits/stdc++.h>
using namespace std;

int main() {
    string dividend;  // 被除数，用字符串表示的大整数
    long long divisor; // 除数，长整型数
    cin >> dividend >> divisor;

    // 特殊情况处理：如果被除数为"0"或除数为0，直接输出0
    if (dividend == "0" || divisor == 0) {
        cout << 0;
        return 0;
    }

    long long len = dividend.size(); // 获取被除数的长度
    long long remainder = dividend[0] - '0'; // 初始化余数为第一个数字
    bool hasStarted = false; // 标记是否已经开始输出非零的商

    // 从第二位开始逐位计算商
    for (long long i = 1; i < len; i++) {
        // 将当前余数乘10并加上下一位数字，构成当前被除数
        long long current_dividend = remainder * 10 + (dividend[i] - '0');
        long long quotient_digit = current_dividend / divisor; // 计算当前位的商
        remainder = current_dividend % divisor; // 更新余数

        // 输出商的当前位
        if (quotient_digit > 0) {
            cout << quotient_digit; // 输出非零商位
            hasStarted = true; // 标记已开始输出
        } else if (hasStarted) {
            cout << 0; // 如果已开始输出，则即使商为0也输出
        }
    }

    // 如果整个循环未输出任何商，说明结果为0
    if (!hasStarted) {
        cout << 0;
    }

    return 0;
}