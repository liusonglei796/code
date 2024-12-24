#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 30000; // 定义数组最大长度

// 高精度乘法函数
void multiply(int *result, int &length, int num) {
    int carry = 0;
    for (int i = 0; i < length; ++i) {
        int temp = result[i] * num + carry;
        result[i] = temp % 10;
        carry = temp / 10;
    }
    while (carry) {
        result[length++] = carry % 10;
        carry /= 10;
    }
}

// 计算阶乘并统计特定数码出现的次数
int countDigitInFactorial(int n, int digit) {
    int result[MAXN] = {0}; // 初始化结果数组
    result[0] = 1; // 0! = 1
    int length = 1; // 当前结果的长度

    for (int i = 2; i <= n; ++i) {
        multiply(result, length, i); // 计算阶乘
    }

    int count = 0;
    for (int i = 0; i < length; ++i) {
        if (result[i] == digit) {
            ++count; // 统计特定数码出现的次数
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a;
        cin >> n >> a;
        cout << countDigitInFactorial(n, a) << endl;
    }
    return 0;
}