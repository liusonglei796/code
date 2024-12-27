#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 比较函数，判断ab和ba哪个更大
bool compare(const string& a, const string& b) {
    return a + b>b + a;
}

int main() {
    int n;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    // 对数字字符串进行排序
    sort(nums.begin(), nums.end(), compare);
    string result = "";
    for (const string& num : nums) {
        result += num;
    }
    // 去除前导0
    int i = 0;
    while (result[i]=='0'&&i + 1<result.length()) {
        i++;
    }
    result = result.substr(i);
    cout << result << endl;
    return 0;
}