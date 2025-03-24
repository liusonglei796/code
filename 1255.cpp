#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 高精度加法
string add(const string& a, const string& b) {
    string c = "";
    int t = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || t) {
        if (i >= 0) t += a[i--] - '0';
        if (j >= 0) t += b[j--] - '0';
        c += to_string(t % 10);
        t /= 10;
    }
    reverse(c.begin(), c.end());
    return c;
}

int main() {
    int n;
    cin >> n;

    if (n <= 2) {
        cout << n << endl;
        return 0;
    }

    string dp[n + 1];
    dp[1] = "1";
    dp[2] = "2";

    for (int i = 3; i <= n; ++i) {
        dp[i] = add(dp[i - 1], dp[i - 2]);
    }

    cout << dp[n] << endl;

    return 0;
}