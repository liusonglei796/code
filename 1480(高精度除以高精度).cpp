#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 移除字符串前导零
string removeLeadingZeros(const string& s) {
    size_t firstNonZero = s.find_first_not_of('0');
    if (firstNonZero == string::npos) return "0";
    return s.substr(firstNonZero);
}

// 比较两个数字字符串的大小（忽略符号）
int compare(const string& a, const string& b) {
    if (a.size() > b.size()) return 1;
    if (a.size() < b.size()) return -1;
    return a.compare(b);
}

// 高精度减法，假设 a >= b
string subtract(const string& a, const string& b) {
    string result;
    int borrow = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    while (i >= 0 || j >= 0) {
        int digitA = i >= 0 ? a[i] - '0' : 0;
        int digitB = j >= 0 ? b[j] - '0' : 0;
        int diff = digitA - digitB - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(diff + '0');
        i--;
        j--;
    }
    reverse(result.begin(), result.end());
    return removeLeadingZeros(result);
}

// 高精度乘法，数字字符串乘以单数字（0-9）
string multiply(const string& a, int b) {
    if (b == 0) return "0";
    string result;
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        int digit = a[i] - '0';
        int product = digit * b + carry;
        carry = product / 10;
        result.push_back((product % 10) + '0');
    }
    while (carry > 0) {
        result.push_back((carry % 10) + '0');
        carry /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

// 计算当前部分被除数除以除数的商的单一位，并更新 current
int findQuotientDigit(string& current, const string& divisor) {
    if (compare(current, divisor) < 0) return 0;
    for (int q = 9; q >= 1; q--) {
        string product = multiply(divisor, q);
        if (compare(product, current) <= 0) {
            current = subtract(current, product);
            return q;
        }
    }
    return 0;
}

// 高精度除法，返回商的字符串
string divide(string dividend, string divisor) {
    // 处理符号
    bool positive = true;
    if (dividend[0] == '-') {
        positive = !positive;
        dividend = dividend.substr(1);
    }
    if (divisor[0] == '-') {
        positive = !positive;
        divisor = divisor.substr(1);
    }
    dividend = removeLeadingZeros(dividend);
    divisor = removeLeadingZeros(divisor);

    // 特殊情况
    if (divisor == "0") {
        throw invalid_argument("除数不能为零");
    }
    if (dividend == "0") {
        return "0";
    }
    if (compare(dividend, divisor) < 0) {
        return "0";
    }

    // 长除法
    string quotient;
    string current = "";
    for (char digit : dividend) {
        current += digit;
        current = removeLeadingZeros(current);
        int q = findQuotientDigit(current, divisor);
        quotient += (q + '0');
    }
    quotient = removeLeadingZeros(quotient);
    return positive ? quotient : "-" + quotient;
}

int main() {
    string a, b;
    cin >> a >> b;
    try {
        string result = divide(a, b);
        cout << result << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    return 0;
}