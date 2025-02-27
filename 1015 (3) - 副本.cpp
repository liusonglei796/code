#include <iostream>
#include <string>
#include <algorithm>

// 判断一个字符串是否是回文数
// 回文数即从左向右读与从右向左读都一样的数
bool isPalindrome(const std::string& num) {
    // 初始化左指针，指向字符串的起始位置
    int left = 0;
    // 初始化右指针，指向字符串的末尾位置
    int right = num.length() - 1;
    // 当左指针小于右指针时，继续循环比较
    while (left < right) {
        // 如果左右指针所指的字符不相等，说明不是回文数，返回 false
        if (num[left] != num[right]) {
            return false;
        }
        // 左指针右移一位
        left++;
        // 右指针左移一位
        right--;
    }
    // 循环结束都没有发现不相等的情况，说明是回文数，返回 true
    return true;
}

// 进行 N 进制加法
// num1 和 num2 是要相加的两个 N 进制数，以字符串形式表示
// base 表示进制，如 2 进制、10 进制、16 进制等
std::string add(const std::string& num1, const std::string& num2, int base) {
    // 用于存储相加结果的字符串
    std::string result;
    // 进位标志，初始化为 0
    int carry = 0;
    // i 指向 num1 的最后一个字符
    int i = num1.length() - 1;
    // j 指向 num2 的最后一个字符
    int j = num2.length() - 1;

    // 只要 num1 或 num2 还有未处理的字符，或者还有进位，就继续循环
    while (i >= 0 || j >= 0 || carry) {
        // 先将进位加到总和中
        int sum = carry;
        // 如果 num1 还有未处理的字符
        if (i >= 0) {
            // 如果当前字符是数字字符（'0' - '9'）
            if (num1[i] >= '0' && num1[i] <= '9') {
                // 将字符转换为对应的数字并加到总和中
                sum += num1[i] - '0';
            } else {
                // 如果是字母字符（'A' - 'F'，用于 16 进制），转换为对应的数字并加到总和中
                sum += num1[i] - 'A' + 10;
            }
            // 处理完一个字符，i 减 1
            i--;
        }
        // 如果 num2 还有未处理的字符
        if (j >= 0) {
            // 如果当前字符是数字字符（'0' - '9'）
            if (num2[j] >= '0' && num2[j] <= '9') {
                // 将字符转换为对应的数字并加到总和中
                sum += num2[j] - '0';
            } else {
                // 如果是字母字符（'A' - 'F'，用于 16 进制），转换为对应的数字并加到总和中
                sum += num2[j] - 'A' + 10;
            }
            // 处理完一个字符，j 减 1
            j--;
        }
        // 计算新的进位，总和除以进制得到进位
        carry = sum / base;
        // 计算当前位的结果，总和对进制取模得到当前位的值
        sum %= base;
        // 如果当前位的值小于 10，转换为数字字符添加到结果字符串中
        if (sum < 10) {
            result.push_back(sum + '0');
        } else {
            // 如果当前位的值大于等于 10，转换为字母字符（'A' - 'F'）添加到结果字符串中
            result.push_back(sum - 10 + 'A');
        }
    }
    // 由于加法是从低位到高位处理的，结果字符串是逆序的，需要反转
    std::reverse(result.begin(), result.end());
    // 返回相加后的结果字符串
    return result;
}

// 反转字符串
// 将输入的字符串反转后返回
std::string reverse(const std::string& num) {
    // 复制输入的字符串
    std::string reversed = num;
    // 使用标准库的 reverse 函数反转字符串
    std::reverse(reversed.begin(), reversed.end());
    // 返回反转后的字符串
    return reversed;
}

int main() {
    // 存储进制，如 2、10、16 等
    int base;
    // 存储输入的 N 进制数，以字符串形式表示
    std::string num;
    // 从标准输入读取进制和 N 进制数
    std::cin >> base >> num;

    // 记录操作步数，初始化为 0
    int steps = 0;
    // 最多进行 30 步操作
    while (steps <= 30) {
        // 如果当前数字是回文数
        if (isPalindrome(num)) {
            // 输出达到回文数所需的步数
            std::cout << "STEP=" << steps << std::endl;
            // 程序正常结束
            return 0;
        }
        // 反转当前数字
        std::string reversed = reverse(num);
        // 将当前数字和反转后的数字相加，更新当前数字
        num = add(num, reversed, base);
        // 步数加 1
        steps++;
    }
    // 如果 30 步内没有得到回文数，输出 Impossible!
    std::cout << "Impossible!" << std::endl;
    // 程序正常结束
    return 0;
}