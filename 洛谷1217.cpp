#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x % 10 == 0 && x!= 0) {
            return false;
        }
        int res = 0;
        while (x > res) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res == x || x == res / 10;
    }
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    int sqrt_num = sqrt(num);
    for (int i = 5; i <= sqrt_num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}
};

int main() {
    Solution c;
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        // 先跳过大于2的偶数，只判断奇数（除了2）和2本身
        if (i > 2 && i % 2 == 0) continue;
        if (c.isPalindrome(i) && c.isPrime(i)) {
            cout << i << endl;
        }
    }
    return 0;
}