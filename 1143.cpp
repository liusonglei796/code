#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 函数：将任意进制数转换为十进制
long long to_decimal(int base, const string& num) {
    long long result = 0;
    for (char c : num) {
        int digit;
        if (isdigit(c)) {
            digit = c - '0';
        } else {
            digit = 10 + (c - 'A');
        }
        result = result * base + digit;
    }
    return result;
}

// 函数：将十进制数转换为任意进制
string to_base(int base, long long num) {
    if (num == 0) {
        return "0";
    }
    string digits = "0123456789ABCDEF";
    string result;
    while (num > 0) {
        int remainder = num % base;
        result += digits[remainder];
        num /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n, m;
    string num;

    // 输入原始进制和目标进制
    cin >> n >> num >> m;

    // 将输入的n进制数转换为十进制
    long long decimal_value = to_decimal(n, num);

    // 将十进制数转换为目标m进制
    string result = to_base(m, decimal_value);

    // 输出结果
    cout << result << endl;

    return 0;
}