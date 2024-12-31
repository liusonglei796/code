#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    long long n, c;
    cin >> n >> c;
    int arr[2 * 100000];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    unordered_map<int, int> num_count;  // 哈希表，键为数字，值为该数字出现的次数
    // 统计每个数字出现的次数
    for (int i = 0; i < n; ++i) {
        num_count[arr[i]]++;
    }
    long long count = 0;
    // 遍历数组，查找满足条件的数对
    for (int i = 0; i < n; ++i) {
        int target = arr[i] - c;
        if (num_count.find(target)!= num_count.end()) {
            count += num_count[target];
        }
    }
    cout << count << endl;
    return 0;
}