#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> ans;  // 存储所有合法方案
vector<int> temp(10);     // 临时存储当前方案，改为10

// DFS搜索所有可能的配料组合
void dfs(int pos, int sum) {
    // 如果已经处理完10种配料
    if(pos == 10) {      // 改为10
        // 如果总和等于目标值n，记录这个方案
        if(sum == n) {
            ans.push_back(temp);
        }
        return;
    }
    
    // 每种配料可以放1到3克
    for(int i = 1; i <= 3; i++) {
        // 剪枝：如果当前和加上最少的量(每种都放1克)都超过n，就不用继续了
        if(sum + i + (9-pos) > n) continue;  // 改为9-pos
        // 剪枝：如果当前和加上最多的量(每种都放3克)都达不到n，也不用继续
        if(sum + i + (9-pos)*3 < n) continue;  // 改为9-pos
        
        temp[pos] = i;
        dfs(pos+1, sum+i);
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
    
    // 从第0种配料开始搜索
    dfs(0, 0);  // 改为从0开始
    
    // 输出方案数
    cout << ans.size() << endl;
    
    // 输出所有方案
    for(const auto& v : ans) {
        for(int i = 0; i < 10; i++) {  // 改为0到9
            cout << v[i] << (i == 9 ? '\n' : ' ');  // 改为9
        }
    }
    
    return 0;
}