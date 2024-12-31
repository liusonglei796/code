#include <iostream>
#include <string>
using namespace std;

int main() {
    string num;
    int k;
    cin >> num >> k;
    while (k > 0) {
        int len = num.size();
        for (int i = 0; i < len - 1; ++i) {
            if (num[i] > num[i + 1]) {
                num.erase(i, 1);  // 删除当前较大的高位数字
                break;
            }
        }
        if (num.size() == len) {  // 如果没有找到可删除的更大高位数字，就删除最后一位（比如全是递增序列情况）
            num.erase(len - 1, 1);
        }
        k--;
    }
    // 去除前导0（如果存在）
    int start = 0;
    while (start < num.size() && num[start] == '0') {
        start++;
    }
    if (start == num.size()) {  // 如果全是0的情况，输出一个0
        cout << 0 << endl;
    } else {
        cout << num.substr(start) << endl;
    }
    return 0;
}