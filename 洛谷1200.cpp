#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

     int c = 1;  // 用于存储彗星名转换并取余后的结果，初始化为1
     int d = 1;  // 用于存储小组名转换并取余后的结果，初始化为1

    // 计算彗星名对应的取余结果
    for (char ch : a) {
        int num1 = ch - 'A' + 1;
        c *= num1;
        c %= 47;  // 每步乘法后取余，避免整数溢出并符合题目逻辑
    }

    // 计算小组名对应的取余结果
    for (char ch : b) {
        int num2 = ch - 'A' + 1;
        d *= num2;
        d %= 47;  // 每步乘法后取余，避免整数溢出并符合题目逻辑
    }

    if (c == d) {
        cout << "GO" << endl;
    } else {
        cout << "STAY" << endl;
    }

    return 0;
}