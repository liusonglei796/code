#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    queue<int> q;

    // 初始化队列
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    // 模拟约瑟夫问题
    int count = 0;
    while (!q.empty()) {
        int person = q.front();
        q.pop();
        count++;
        if (count == m) {
            cout << person << " ";
            count = 0;
        } else {
            q.push(person);
        }
    }

    cout << endl;
    return 0;
}