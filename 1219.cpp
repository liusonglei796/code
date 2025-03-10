#include<bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
vector<int> pos;  // 存储每行皇后的列位置
vector<bool> col;  // 列是否被占用
vector<bool> diag1;  // 主对角线 row-col+n-1
vector<bool> diag2;  // 副对角线 row+col

void printSolution() {
    if(cnt < 3) {  // 只打印前3个解
        for(int i = 0; i < n; i++) {
            cout << pos[i] + 1 << " ";
        }
        cout << endl;
    }
    cnt++;
}

void dfs(int row) {
    if(row == n) {
        printSolution();
        return;
    }
    
    for(int j = 0; j < n; j++) {
        // 主对角线：row-j+n-1的范围是[0, 2n-2]
        // 副对角线：row+j的范围是[0, 2n-2]
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
    pos.resize(n);
    col.resize(n, false);
    // 对角线数组大小应为2n-1
    diag1.resize(2*n-1, false);  // row-col+n-1: 0 到 2n-2
    diag2.resize(2*n-1, false);  // row+col: 0 到 2n-2
    
    dfs(0);
    cout << cnt << endl;  // 输出解的总数
    
    return 0;
}