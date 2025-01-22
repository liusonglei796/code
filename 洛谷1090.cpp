```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n; // 输入元素的个数
    // 创建一个小顶堆（默认是大顶堆，这里通过自定义比较函数实现小顶堆）
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num; // 输入每个元素
        pq.push(num); // 将元素加入小顶堆
    }

    int result = 0; // 初始化结果
    while (pq.size() > 1) {
        int min1 = pq.top(); // 取出最小元素
        pq.pop(); // 弹出最小元素
        int min2 = pq.top(); // 取出第二小元素
        pq.pop(); // 弹出第二小元素
        int sum = min1 + min2; // 计算两最小元素之和
        result += sum; // 累加到结果中
        pq.push(sum); // 将和重新加入小顶堆
    }

    cout << result << endl; // 输出结果
    return 0; // 返回 0 表示程序执行成功
}
```
