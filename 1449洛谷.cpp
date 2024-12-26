#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<int> st;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            int num = 0;
            while (s[i]!= '.') {
                num = num * 10 + (s[i] - '0');
                ++i;
            }
            st.push(num);
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            int result;
            if (s[i] == '+') {
                result = num1 + num2;
            } else if (s[i] == '-') {
                result = num1 - num2;
            } else if (s[i] == '*') {
                result = num1 * num2;
            } else if (s[i] == '/') {
                result = num1 / num2;
            }
            st.push(result);
        }
    }
    cout << st.top() << endl;
    return 0;
}