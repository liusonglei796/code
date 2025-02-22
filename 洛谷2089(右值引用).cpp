#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> ans;  // 存储所有合法方案
vector<int> temp(11);     // 临时存储当前方案

void dfs(int pos, int&& sum) {
    if (pos == 11) {
        if (sum == n) {
            ans.push_back(temp);
        }
        return;
    }

    for (int i = 1; i <= 3; i++) {
        if (sum + i + (10 - pos) > n) continue;
        if (sum + i + (10 - pos) * 3 < n) continue;

        temp[pos] = i;
        sum += i;
        dfs(pos + 1, std::move(sum));
        sum -= i;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    // 如果n小于10（每种放1克）或大于30（每种放3克），无解
    if(n < 10 || n > 30) {
        cout << 0 << endl;
        return 0;
    }
    
    // 从第1种配料开始搜索
    dfs(1, 0);
    
    // 输出方案数
    cout << ans.size() << endl;
    
    // 输出所有方案
    for(const auto& v : ans) {
        for(int i = 1; i <= 10; i++) {
            cout << v[i] << (i == 10 ? '\n' : ' ');
        }
    }
    
    return 0;
}