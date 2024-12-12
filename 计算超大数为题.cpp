#include <iostream>
#include <vector>
#include <string>

// 大整数乘法，模拟手算乘法
void multiplyByTwo(std::string& num) {
    int carry = 0;
    for (size_t i = 0; i < num.length(); ++i) {
        int digit = (num[i] - '0') * 2 + carry;
        num[i] = (digit % 10) + '0';
        carry = digit / 10;
    }
    if (carry > 0) {
        num += (carry + '0');
    }
}

int main() {
    int t;
    std::cin >> t;
    std::vector<int> inputs;
    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;
        inputs.push_back(n);
    }

    for (int n : inputs) {
        std::string result = "1";
        for (int i = 0; i < n; ++i) {
            multiplyByTwo(result);
        }
        std::cout << result << " ";
    }
    std::cout << std::endl;

    return 0;
}