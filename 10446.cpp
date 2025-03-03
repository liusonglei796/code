#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 字符串乘法函数，模拟手工乘法
string multiply_strings(const string& str_a, const string& str_b) {
    int len_a = str_a.size();
    int len_b = str_b.size();
    vector<int> result(len_a + len_b, 0);  // 用于存储乘法结果

    // 从右到左逐位相乘
    for (int i = len_a - 1; i >= 0; i--) {
        for (int j = len_b - 1; j >= 0; j--) {
            int mul = (str_a[i] - '0') * (str_b[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j] += sum / 10;  // 处理进位
            result[i + j + 1] = sum % 10;  // 当前位的值
        }
    }

    // 将结果转换为字符串
    string result_str;
    for (int num : result) {
        if (!(result_str.empty() && num == 0)) {  // 去掉前导零
            result_str.push_back(num + '0');
        }
    }

    return result_str.empty() ? "0" : result_str;
}

// 将字符串表示的数字对p取模
long long mod_from_string(const string& str, long long p) {
    long long num = 0;
    for (char c : str) {
        num = (num * 10 + (c - '0')) % p;
    }
    return num;
}

int main() {
    long long a, b, p;
    cin >> a >> b >> p;

    // 先对a和b取模
    a %= p;
    b %= p;

    // 转换为字符串
    string str_a = to_string(a);
    string str_b = to_string(b);

    // 字符串乘法
    string result_str = multiply_strings(str_a, str_b);

    // 将结果字符串对p取模
    long long result = mod_from_string(result_str, p);

    cout << result << endl;

    return 0;
}