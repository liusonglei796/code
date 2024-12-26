#include <iostream>
#include <deque>
#include <stack>
#include <vector>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> sk;
    int j = 0;  // 用于遍历popped序列的索引
    for (int num : pushed) {
        sk.push(num);
        while (!sk.empty() && sk.top() == popped[j]) {
            sk.pop();
            j++;
        }
    }
    return sk.empty();
}

int main() {
    int q;  // 询问次数
    cin >> q;
    while (q--) {
        int n;  // 序列长度
        cin >> n;
        vector<int> pushed(n);
        vector<int> popped(n);
        for (int i = 0; i < n; ++i) {
            cin >> pushed[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> popped[i];
        }
        if (validateStackSequences(pushed, popped)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}