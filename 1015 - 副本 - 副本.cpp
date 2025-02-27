#include <iostream>
#include <string>
#include <algorithm>

// 判断一个字符串是否是回文数
bool isPalindrome(const std::string& num) {
    int left = 0, right = num.length() - 1;
    while (left < right) {
        if (num[left] != num[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// 进行 N 进制加法
std::string add(const std::string& num1, const std::string& num2, int base) {
    std::string result;
    int carry = 0;
    int i = num1.length() - 1, j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            if (num1[i] >= '0' && num1[i] <= '9') {
                sum += num1[i] - '0';
            } else {
                sum += num1[i] - 'A' + 10;
            }
            i--;
        }
        if (j >= 0) {
            if (num2[j] >= '0' && num2[j] <= '9') {
                sum += num2[j] - '0';
            } else {
                sum += num2[j] - 'A' + 10;
            }
            j--;
        }
        carry = sum / base;
        sum %= base;
        if (sum < 10) {
            result.push_back(sum + '0');
        } else {
            result.push_back(sum - 10 + 'A');
        }
    }
    std::reverse(result.begin(), result.end());
    return result;
}

// 反转字符串
std::string reverse(const std::string& num) {
    std::string reversed = num;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

int main() {
    int base;
    std::string num;
    std::cin >> base >> num;

    int steps = 0;
    while (steps <= 30) {
        if (isPalindrome(num)) {
            std::cout << "STEP=" << steps << std::endl;
            return 0;
        }
        std::string reversed = reverse(num);
        num = add(num, reversed, base);
        steps++;
    }
    std::cout << "Impossible!" << std::endl;
    return 0;
}