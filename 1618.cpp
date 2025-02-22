#include<bits/stdc++.h>
using namespace std;

int a, b, c;
vector<int> path(9);  // 当前路径
vector<vector<int>> ans;
bool used[10];     // 记录数字1-9的使用情况

void dfs(int depth) {
    if(depth == 9) {  // 收集到9个数字
        int n1 = path[0]*100 + path[1]*10 + path[2];
        int n2 = path[3]*100 + path[4]*10 + path[5];
        int n3 = path[6]*100 + path[7]*10 + path[8];
        
        if(n1 * b == n2 * a && n1 * c == n3 * a) {
            ans.push_back({n1, n2, n3});
        }
        return;
    }
    //每次都从1到9遍历用used数组标记已用数字不需要start参数这样才能得到所有可能的排列
    for(int i = 1; i <= 9; i++) {
        if(!used[i]) {
            used[i] = true;
          path[depth]=i;
            dfs(depth + 1);
            used[i] = false;
        }
    }
}

int main() {
    cin >> a >> b >> c;
    memset(used, 0, sizeof(used));
    
    dfs(0);
    
    if(ans.empty()) {
        cout << "No!!!" << endl;
    } else {
        for(const auto& v : ans) {
            cout << v[0] << " " << v[1] << " " << v[2] << endl;
        }
    }
    return 0;
}