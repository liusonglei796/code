#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Kadane 算法：求一维数组的最大子数组和
int kadane(const vector<int>& arr) {
    int maxSum = INT_MIN;
    int currentSum = 0;
    for (int num : arr) {
        currentSum = max(num, currentSum + num);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main() {
    int n;
    cin >> n;

    // 输入矩阵
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int maxRectangleSum = INT_MIN;

    // 遍历所有可能的行对 (i, j)
    for (int i = 0; i < n; i++) {
        vector<int> temp(n, 0); // 用于存储从第 i 行到第 j 行的列和
        for (int j = i; j < n; j++) {
            // 计算从第 i 行到第 j 行的列和
            for (int k = 0; k < n; k++) {
                temp[k] += matrix[j][k];
            }
            // 对 temp 数组使用 Kadane 算法
            int currentMax = kadane(temp);
            maxRectangleSum = max(maxRectangleSum, currentMax);
        }
    }

    cout << maxRectangleSum << endl;

    return 0;
}