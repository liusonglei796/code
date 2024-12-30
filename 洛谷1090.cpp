#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    // 创建一个小顶堆（默认是大顶堆，这里通过自定义比较函数实现小顶堆）
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        pq.push(num);
    }

    int result = 0;
    while (pq.size() > 1) {
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        int sum = min1 + min2;
        result += sum;
        pq.push(sum);
    }

    cout << result << endl;
    return 0;
}