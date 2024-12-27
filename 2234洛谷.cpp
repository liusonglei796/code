#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sales(n);
    for (int i = 0; i < n; ++i) {
        cin >> sales[i];
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int minDiff = (i == 0)? sales[0] : 1e9;
        for (int j = 0; j < i; ++j) {
            minDiff = min(minDiff, abs(sales[j] - sales[i]));
        }
        sum += minDiff;
    }

    cout << sum << endl;
    return 0;
}