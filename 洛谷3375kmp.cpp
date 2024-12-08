#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 计算next数组，用于记录模式串每个前缀的最长border长度
vector<int> getNext(const string& pattern) {
    int m = pattern.size();
    vector<int> next(m, 0);
    int j = 0;
    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        next[i] = j;
    }
    return next;
}

// 使用KMP算法在文本串中查找模式串出现的位置
vector<int> kmpSearch(const string& text, const string& pattern) {
    vector<int> result;
    int n = text.size();
    int m = pattern.size();
    vector<int> next = getNext(pattern);
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == m) {
                result.push_back(i - m); // 找到匹配，记录位置
                j = next[j - 1]; // 继续寻找下一个匹配
            }
        } else {
            if (j != 0) {
                j = next[j - 1]; // 回退到上一个可能的匹配位置
            } else {
                i++; // 没有匹配，移动到下一个字符
            }
        }
    }
    return result;
}

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;

    vector<int> positions = kmpSearch(s1, s2);
    for (int pos : positions) {
        cout << pos + 1 << endl;  // 输出位置按题目要求从1开始计数，所以要加1
    }

    vector<int> next = getNext(s2);
    for (int i = 0; i < s2.size(); ++i) {
        cout << next[i] << " ";
    }
    cout << endl;

    return 0;
}
