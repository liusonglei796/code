#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int carry = 0; // 修正carry的初始值和类型
    int i = 0;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string s3;
    while (i < max(s1.size(), s2.size()) || carry) {
        int x = i < s1.size() ? s1[i] - '0' : 0;
        int y = i < s2.size() ? s2[i] - '0' : 0;
        int sum = x + y + carry;
        carry = sum / 10; // 修正carry的更新方式
        int a = sum % 10;
        string b = to_string(a);
        s3 += b;
        i++;
    }
    reverse(s3.begin(), s3.end());
    if (s3.empty()) {
        cout << "0"; // 如果s3为空，则输出0
    } else {
        cout << s3;
    }
    return 0;
}