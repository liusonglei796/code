#include <bits/stdc++.h>
using namespace std;

int n;
vector<bool> chosen(15);

void dfs(int pos) {
    // 当处理完所有位置时，输出当前方案
    if (pos > n) {
        for (int i = 1; i <= n; i++) {
            cout << (chosen[i] ? "Y" : "N");
        }
        cout << endl;
        return;
    }
    //子集枚举：每个位置只需决定选/不选，状态相互独立  • 排列/组合：需要从多个选项中选择一个，选择会相互影响，因此需要显式回溯
    // 不选当前位置
    chosen[pos] = false;
    dfs(pos + 1);
    
    // 选当前位置
    chosen[pos] = true;
    dfs(pos + 1);
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}
