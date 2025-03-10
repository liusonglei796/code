#include<bits/stdc++.h>
using namespace std;
//逐行放置皇后（row从1开始）
//每行尝试不同的列位置（j从1到n）
//检查三个约束条件（列、主对角线、副对角线）
int n;
int cnt = 0;
vector<int> pos;  // 存储每行皇后的列位置，索引从1开始
vector<bool> col;  // 列是否被占用，索引从1开始
vector<bool> diag1;  // 主对角线 row-col+n-1
vector<bool> diag2;  // 副对角线 row+col

void printSolution() {
    if(cnt < 3) {  // 只打印前3个解
        for(int i = 1; i <= n; i++) {
            cout << pos[i] << " ";
        }
        cout << endl;
    }
    cnt++;
}
void dfs(int row) {
    if(row == n + 1) {  // 终止条件是 row == n+1
        printSolution();
        return;
    }    
    for(int j = 1; j <= n; j++) {  // j 从1开始
        // 主对角线：row-j+n-1的范围是[0, 2n-2]
        // 副对角线：row+j的范围是[2, 2n]
        // j 从0开始
        // 主对角线：row-j+n-1的范围是[0, 2*n-2]
        // 副对角线：row+j的范围是[0,2*n-2]
        if(!col[j] && !diag1[row-j+n-1] && !diag2[row+j]) {
            pos[row] = j;
            col[j] = true;
            diag1[row-j+n-1] = true;
            diag2[row+j] = true;
            dfs(row + 1);
            // 回溯
            col[j] = false;
            diag1[row-j+n-1] = false;
            diag2[row+j] = false;
        }
    }
}

int main() {
    cin >> n;
    
    // 初始化数组
    pos.resize(n + 1);  // 索引从1开始
    col.resize(n + 1, false);  // 索引从1开始
    diag1.resize(2 * n - 1, false);  // row-col+n-1: 0 到 2n-2
    diag2.resize(2 * n + 1, false);  // row+j: 2 到 2n
    
    dfs(1);  // 从1开始
    cout << cnt << endl;  // 输出解的总数
    
    return 0;
}