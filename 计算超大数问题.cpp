#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 模拟两个大整数（用字符串表示）相加，返回相加后的结果字符串
string addStrings(const string& num1, const string& num2) {
    string result = "";
    int i = num1.size() - 1, j = num2.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        carry = sum / 10;
        result += (sum % 10 + '0');
    }
    reverse(result.begin(), result.end());
    return result;
}

// 模拟两个大整数（用字符串表示）相乘，返回相乘后的结果字符串
string multiplyString(const string& num1, const string& num2) {
    if (num1 == "0" || num2 == "0") return "0";
    string result = "0";
    for (int i = num2.size() - 1; i >= 0; --i) {
        int digit2 = num2[i] - '0';
        string temp = "";
        int carry = 0;
        for (int j = num1.size() - 1; j >= 0; --j) {
            int digit1 = num1[j] - '0';
            int product = digit1 * digit2 + carry;
            carry = product / 10;
            temp += (product % 10 + '0');
        }
        if (carry > 0) temp += (carry + '0');
        reverse(temp.begin(), temp.end());
        temp += string(num2.size() - 1 - i, '0');
        result = addStrings(result, temp);
    }
    return result;
}

// 计算n个圆最多分割区域数对应的字符串表示
string calculateMaxRegions(const string& nStr) {
    // 计算n * n
    string nSquare = multiplyString(nStr, nStr);
    // 计算n * n - n
    string nSub = "";
    int borrow = 0;
    for (int i = nSquare.size() - 1, j = nStr.size() - 1; i >= 0 || j >= 0; --i, --j) {
        int digit1 = (i >= 0? nSquare[i] - '0' : 0);
        int digit2 = (j >= 0? nStr[j] - '0' : 0);
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        nSub += (diff + '0');
    }
    while (nSub.size() > 1 && nSub.back() == '0') {
        nSub.pop_back();
    }
    reverse(nSub.begin(), nSub.end());
    // 计算n * n - n + 2
    string two = "2";
    return addStrings(addStrings(nSub, two), "");
}

int main() {
    int t;
    cin >> t;
    vector<string> inputs;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        inputs.push_back(to_string(n));
    }

    for (const string& nStr : inputs) {
        if (nStr == "0") {
            cout << "1 ";
            continue;
        }
        string resultStr = calculateMaxRegions(nStr);
        cout << resultStr << " ";
    }
    cout << endl;

    return 0;
}