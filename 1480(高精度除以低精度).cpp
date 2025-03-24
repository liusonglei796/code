#include <iostream> // 引入输入输出流库
#include <string>   // 引入字符串库
#include <algorithm> // 引入算法库，虽然本例中没有使用，但通常在高精度计算中会用到

using namespace std; // 使用标准命名空间

// 定义一个函数，用于高精度整数除以低精度整数
string divide(string a, int b) {
    string result = ""; // 初始化结果字符串，用于存储商
    long long remainder = 0; // 初始化余数，使用 long long 防止溢出

    // 遍历被除数 a 的每一位
    for (char digit : a) {
        remainder = remainder * 10 + (digit - '0'); // 更新余数：余数 * 10 + 当前位数字
        result += to_string(remainder / b); // 计算商，并将其转换为字符串追加到结果中
        remainder %= b; // 更新余数为除以 b 的余数
    }

    // 处理结果字符串中的前导零
    size_t start = result.find_first_not_of('0'); // 找到第一个非零字符的位置
    if (start == string::npos) { // 如果没有非零字符，说明商为 0
        return "0"; // 返回 "0"
    }
    return result.substr(start); // 返回去除前导零后的商
}

int main() {
    string a; // 存储被除数
    int b;    // 存储除数

    cin >> a >> b; // 从标准输入读取被除数和除数
    cout << divide(a, b) << endl; // 调用 divide 函数计算商，并输出结果

    return 0; // 程序正常结束
}