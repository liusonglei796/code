#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 比较两个字符串表示的大整数大小
bool compare(string a, string b) {
    if (a.size()!= b.size()) {
        return a.size() > b.size();
    }
    for (int i = 0; i < a.size(); ++i) {
        if (a[i]!= b[i]) {
            return a[i] > b[i];
        }
    }
    return true;
}

// 高精度减法函数
string highPrecisionSub(string a, string b) {
    bool isNegative = false;  // 标记结果是否为负数
    // 如果a小于b，交换a和b，并标记结果为负数
    if (!compare(a, b)) {
        swap(a, b);
        isNegative = true;
    }
    int n1 = a.size() - 1;
    int n2 = b.size() - 1;
    string result;
    while (n1 >= 0 || n2 >= 0) {
        int x = n1 >= 0? a[n1--] - '0' : 0;
        int y = n2 >= 0? b[n2--] - '0' : 0;
        int sub = x - y;
        if (sub < 0) {
            sub = x + 10 - y;
            int idx = n1;
            while (idx >= 0 && a[idx] == '0') {
                a[idx] = '9';
                idx--;
            }
            if (idx >= 0) {
                a[idx] = a[idx] - '0' - 1 + '0';
            }
        }
        result += to_string(sub);
    }
    // 去除前导0
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }
    if (isNegative) {
        result += '-';
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << highPrecisionSub(a, b) << endl;
    return 0;
}