#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    // 使用vector嵌套，动态分配空间
    vector<vector<int>> lockers;
    lockers.resize(100001);
    while(q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int i, j, k;
            cin >> i >> j >> k;
            // 确保第i个柜子有足够空间
            if(lockers[i].size() <= j) {
                lockers[i].resize(j + 1, 0);
            }
            lockers[i][j] = k;
        } else {
            int i, j;
            cin >> i >> j;
            cout << lockers[i][j] << "\n";
        }
    }
    
    return 0;
}