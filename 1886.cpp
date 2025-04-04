#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    // 单调队列求最小值
    deque<int> minDeque;
    vector<int> minResult;

    for (int i = 0; i < n; ++i) {
        // 维护队列单调性：队首到队尾递增
        while (!minDeque.empty() && a[minDeque.back()] >= a[i]) {
            minDeque.pop_back();
        }
        minDeque.push_back(i);

        // 移除不在窗口范围内的元素
        if (minDeque.front() < i - k + 1) {
            minDeque.pop_front();
        }

        // 当窗口大小达到 k 时记录结果
        if (i >= k - 1) {
            minResult.push_back(a[minDeque.front()]);
        }
    }

    // 单调队列求最大值
    deque<int> maxDeque;
    vector<int> maxResult;

    for (int i = 0; i < n; ++i) {
        // 维护队列单调性：队首到队尾递减
        while (!maxDeque.empty() && a[maxDeque.back()] <= a[i]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(i);

        // 移除不在窗口范围内的元素
        if (maxDeque.front() < i - k + 1) {
            maxDeque.pop_front();
        }

        // 当窗口大小达到 k 时记录结果
        if (i >= k - 1) {
            maxResult.push_back(a[maxDeque.front()]);
        }
    }

    // 输出最小值结果
    for (int val : minResult) cout << val << " ";
    cout << "\n";

    // 输出最大值结果
    for (int val : maxResult) cout << val << " ";
    cout << "\n";

    return 0;
}