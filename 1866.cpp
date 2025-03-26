#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> m(n);
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    
    // 将M_i按升序排序
    sort(m.begin(), m.end());
    
    long long result = 1;
    for (int i = 0; i < n; ++i) {
        // 当前兔子可选的数量是m[i] - i
        int choices = m[i] - i;
        if (choices <= 0) {
            result = 0;
            break;
        }
        result = (result * choices) % MOD;
    }
    
    cout << result << endl;
    return 0;
}