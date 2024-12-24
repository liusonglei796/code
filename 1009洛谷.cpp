#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 高精度加法函数，用于将两个大整数表示的字符串相加
string add(const string &s1, const string &s2) {
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    int carry = 0;
    string s;
    while (i >= 0 || j >= 0 || carry > 0) {
        int x = i >= 0? s1[i] - '0' : 0;
        int y = j >= 0? s2[j] - '0' : 0;
        int sum = x + y + carry;
        s += sum % 10 + '0';
        carry = sum / 10;
        i--;
        j--;
    }
    reverse(s.begin(), s.end());
    return s;
}

// 高精度乘法函数，用于将两个大整数表示的字符串相乘
string multiply(const string &s1, const string &s2) {
    string result = "0";
    for (int i = s1.size() - 1; i >= 0; --i) {
        int carry = 0;
        string temp;
        for (int j = s2.size() - 1; j >= 0; --j) {
            int a = (s1[i] - '0') * (s2[j] - '0') + carry;
            carry = a / 10;
            int b = a % 10;
            temp += b + '0';
        }
        if (carry > 0) {
            temp += carry + '0';
        }
        reverse(temp.begin(), temp.end());
        temp += string(s1.size() - 1 - i, '0');
        result = add(result, temp);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    string sum = "0";
    string factorial = "1";
    for (int i = 1; i <= n; ++i) {
        // 计算当前数的阶乘
        factorial = multiply(factorial, to_string(i));
        // 将当前阶乘累加到总和中
        sum = add(sum, factorial);
    }
    cout << sum << endl;
    return 0;
}