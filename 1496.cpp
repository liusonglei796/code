#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> fires; // 使用pair存储起火区间的起点和终点

  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    fires.push_back({a, b});
  }

  sort(fires.begin(), fires.end()); // 对起火区间按起点进行排序

  int totalLength = 0;
  int currentStart = -2147483648; // 初始化当前区间的起点
  int currentEnd = -2147483648;   // 初始化当前区间的终点

  for (const auto& fire : fires) {
    if (fire.first > currentEnd) { // 如果当前区间与之前的区间没有重叠
      totalLength += currentEnd - currentStart; // 累加之前区间的长度
      currentStart = fire.first; // 更新当前区间的起点
      currentEnd = fire.second; // 更新当前区间的终点
    } else {
      currentEnd = max(currentEnd, fire.second); // 如果有重叠，更新当前区间的终点
    }
  }

  totalLength += currentEnd - currentStart; // 累加最后一个区间的长度

  cout << totalLength << endl;

  return 0;
}