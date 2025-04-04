#include<bits/stdc++.h>
using namespace std;
int n;
vector<bool> col;         // 列是否被访问
vector<bool> diag1;       // 主对角线 (row-col 相同)
vector<bool> diag2;       // 副对角线 (row+col 相同)
vector<int> queens;       
int solutions = 0;        // 解的数量

void dfs(int row) {
    if (row > n) {
        solutions++;
        if (solutions <= 3) {  // 只输出前3个解
            for (int i = 1; i <= n; i++) {
                cout << queens[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int c = 1; c <= n; c++) {
        // 主对角线：row-col 相同
        // 副对角线：row+col 相同
        if (!col[c] && !diag1[row-c+n] && !diag2[row+c]) {
            queens[row] = c;
            col[c] = diag1[row-c+n] = diag2[row+c] = true;
            dfs(row + 1);
            col[c] = diag1[row-c+n] = diag2[row+c] = false;  // 回溯
        }
    }
}

int main() {
    cin >> n;
    col.resize(n + 1, false);
    diag1.resize(2*n, false); 
   // row-col 的范围：
//最小值：当 row=1, col=n 时，1-n = -(n-1)
//最大值：当 row=n, col=1 时，n-1 = n-1
//加上n后的范围：
//最小值：-(n-1) + n = 1
//最大值：(n-1) + n = 2n-1
//所以需要 2n+1 大小来覆盖 [0,2n] 的范围 // 主对角线 row-col+n
    diag2.resize(2*n + 1, false);  // 副对角线 row+col
    // row+col 的范围：
//最小值：当 row=1, col=1 时，1+1 = 2
//最大值：当 row=n, col=n 时，n+n = 2n
//所以需要 2n+1 大小来覆盖 [0,2n] 的范围
    queens.resize(n + 1);
    
    dfs(1);
    cout << solutions << endl;  // 输出总解数
    return 0;
}