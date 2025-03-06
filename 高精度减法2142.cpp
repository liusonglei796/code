#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 移除字符串前导零
string removeLeadingZeros(string s) {
    size_t start = s.find_first_not_of('0');
    if (start == string::npos) return "0";
    return s.substr(start);
}

// 比较两个大整数的绝对值大小（不考虑符号）
int compareAbs(string a, string b) {
    a = removeLeadingZeros(a);
    b = removeLeadingZeros(b);
    if (a.size() > b.size()) return 1; // a > b
    if (a.size() < b.size()) return -1; // a < b
    return a.compare(b); // 逐位比较
}

// 高精度减法（a - b），假设 a >= b
string subtract(string a, string b) {
    string result = "";
    int borrow = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    while (i >= 0 || j >= 0 || borrow != 0) {
        int da = (i >= 0) ? a[i] - '0' : 0;
        int db = (j >= 0) ? b[j] - '0' : 0;
        int diff = da - db - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result = char(diff + '0') + result;
        if (i >= 0) i--;
        if (j >= 0) j--;
    }
    return removeLeadingZeros(result);
}

// 主函数
int main() {
    string a, b;
    cin >> a >> b;
    
    // 移除前导零
    a = removeLeadingZeros(a);
    b = removeLeadingZeros(b);
    
    // 判断符号
    bool negative = false;
    if (compareAbs(a, b) < 0) {
        negative = true;
        swap(a, b); // 确保 a >= b
    }
    
    // 执行减法
    string result = subtract(a, b);
    
    // 添加负号（如果需要）
    if (negative) {
        result = "-" + result;
    }
    
    cout << result << endl;
    return 0;
}