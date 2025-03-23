#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// 判断一个数是否是质数
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string word;
    cin >> word;

    map<char, int> counts; // 使用 map 记录字母出现次数
    for (char c : word) {
        counts[c]++;
    }

    vector<int> freq; // 使用 vector 存储字母出现频率
    for (auto it : counts) {
        freq.push_back(it.second);
    }

    sort(freq.begin(), freq.end()); // 对出现频率进行排序

    int maxn = freq.empty() ? 0 : freq.back(); // 最大出现次数
    int minn = freq.empty() ? 0 : freq.front(); // 最小出现次数

    int diff = maxn - minn;
    if (isPrime(diff)) {
        cout << "Lucky Word" << endl;
        cout << diff << endl;
    } else {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }

    return 0;
}