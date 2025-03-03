#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v1(n);
    for (int i = 0; i < n; ++i) {
        cin >> v1[i];
    }

    // 排序数组
    sort(v1.begin(), v1.end());

    // 找到中位数
    int median = v1[n / 2];

    // 计算与中位数的差的绝对值之和
    int mindistance = 0;
    for (int i = 0; i < n; ++i) {
        mindistance += abs(v1[i] - median);
    }

    cout << mindistance << endl;
    return 0;
}