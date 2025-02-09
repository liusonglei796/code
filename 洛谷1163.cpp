#include <iostream>
#include <iomanip>
using namespace std;

// 根据给定的月利率计算贷款经过 m 个月后的剩余金额
double calculateRemainder(double w0, double w, int m, double rate) {
    double balance = w0;
    for (int i = 0; i < m; ++i) {
        balance = balance * (1 + rate) - w;
    }
    return balance;
}

// 二分查找月利率
double binarySearch(double w0, double w, int m) {
    double left = 0;
    double right = 3;  // 3 表示 300.0%
    double eps = 1e-7;  // 精度要求

    while (right - left > eps) {
        double mid = (left + right) / 2;
        double remainder = calculateRemainder(w0, w, m, mid);

        if (remainder > 0) {
            right = mid;
        } else {
            left = mid;
        }
    }

    return left;
}

int main() {
    double w0, w;
    int m;
    cin >> w0 >> w >> m;

    double rate = binarySearch(w0, w, m);
    cout << fixed << setprecision(1) << rate * 100 << endl;

    return 0;
}