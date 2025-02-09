#include <iostream>
#include <vector>
using namespace std;

// 计算在给定空旷指数下需要增设的路标数量
int calculateRequiredSigns(const vector<int>& signs, int gap, int L) {
    int required = 0;
    for (int i = 1; i < signs.size(); ++i) {
        int distance = signs[i] - signs[i - 1];
        // 计算两个路标间需要增设的路标数量
        required += (distance - 1) / gap; 
    }
    // 考虑最后一个路标到公路终点的距离
    int lastDistance = L - signs.back();
    required += (lastDistance - 1) / gap;
    return required;
}
// 二分查找最小的空旷指数
int binarySearch(const vector<int>& signs, int K, int L) {
    int left = 1;
    int right = L;
    int result = L;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int requiredSigns = calculateRequiredSigns(signs, mid, L);

        if (requiredSigns <= K) {
            // 如果所需增设的路标数量小于等于 K，记录当前空旷指数并尝试更小的值
            result = mid;
            right = mid - 1;
        } else {
            // 如果所需增设的路标数量大于 K，尝试更大的值
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    int L, N, K;
    
    cin >> L >> N >> K;

    vector<int> signs(N);
    for (int i = 0; i < N; ++i) {
        cin >> signs[i];
    }

    int minGap = binarySearch(signs, K, L);
    cout << minGap << endl;

    return 0;
}