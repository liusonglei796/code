#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 去除小数部分末尾多余的0
string removeTrailingZeros(string decimalPart) {
    while (decimalPart.size() > 1 && decimalPart.back() == '0') {
        decimalPart.pop_back();
    }
    return decimalPart;
}

int main() {
    string s;
    cin >> s;

    if (s.find('.')!= string::npos) {  // 处理小数
        size_t dotPos = s.find('.');
        string integerPart = s.substr(0, dotPos);
        string decimalPart = s.substr(dotPos + 1);

        reverse(integerPart.begin(), integerPart.end());
        reverse(decimalPart.begin(), decimalPart.end());

        // 处理整数部分首位为0的情况（原数不为0时）
        if (integerPart[0] == '0' && integerPart.size() > 1) {
            integerPart.erase(0, integerPart.find_first_not_of('0'));
        }

        decimalPart = removeTrailingZeros(decimalPart);


        cout << integerPart << "." << decimalPart << endl;
    } else if (s.find('/')!= string::npos) {  // 处理分数
        size_t slashPos = s.find('/');
        string numerator = s.substr(0, slashPos);
        string denominator = s.substr(slashPos + 1);

        reverse(numerator.begin(), numerator.end());
        reverse(denominator.begin(), denominator.end());

        // 处理分子首位为0的情况（原分子不为0时）
        if (numerator[0] == '0' && numerator.size() > 1) {
            numerator.erase(0, numerator.find_first_not_of('0'));
        }

        // 处理分母首位为0的情况（原分母不为0时）
        if (denominator[0] == '0' && denominator.size() > 1) {
            denominator.erase(0, denominator.find_first_not_of('0'));
        }

        cout << numerator << "/" << denominator << endl;
    } else if (s.back() == '%') {  // 处理百分数
        string numPart = s.substr(0, s.length() - 1);
        reverse(numPart.begin(), numPart.end());

        // 处理数字部分首位为0的情况（原数不为0时）
        if (numPart[0] == '0' && numPart.size() > 1) {
            numPart.erase(0, numPart.find_first_not_of('0'));
        }

        cout << numPart << "%" << endl;
    } else {  // 处理整数
        string reversed = s;
        reverse(reversed.begin(), reversed.end());

        // 处理反转后首位为0的情况（原数不为0时）
        if (reversed[0] == '0' && reversed.size() > 1) {
            reversed.erase(0, reversed.find_first_not_of('0'));
        }

        cout << reversed << endl;
    }

    return 0;
}