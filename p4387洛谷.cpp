#include <iostream>
#include <stack>
using namespace std;

int main() {
    int q;  // 询问次数
    cin >> q;
    for (int i = 0; i < q; ++i) {  // 处理每次询问
        int n;  
        cin >> n;
        int pushed[n];  // 存储入栈序列
        int poped[n];  // 存储出栈序列
        for (int j = 0; j < n; ++j) {
            cin >> pushed[j];  // 输入入栈序列元素
        }
        for (int j = 0; j < n; ++j) {
            cin >> poped[j];  // 输入出栈序列元素
        }

        stack<int> st;  // 创建一个栈用于模拟入栈出栈操作
        int index = 0;  // 用于标记出栈序列当前处理到的位置
        for (int k = 0; k < n; ++k) {
            st.push(pushed[k]);  // 将入栈序列元素依次入栈
            while (!st.empty() && st.top() == poped[index]) {
                // 当栈不为空且栈顶元素和出栈序列当前元素相等时，出栈并移动出栈序列标记位置
                st.pop();
                index++;
            }
        }

        if (st.empty()) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}