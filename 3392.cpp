#include<bits/stdc++.h>
using namespace std;

vector<string> grid;
int n, m;
int changes = 0;

void paint(char color, int start, int end) {
    for(int i = start; i < end; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] != color) {
                changes++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    grid.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    
    int minChanges = INT_MAX;
    // i: 白色结束行
    // j: 蓝色结束行
    for(int i = 0; i < n-2; ++i) {
        for(int j = i+1; j < n-1; ++j) {
            changes = 0;
            paint('W', 0, i+1);    // [0, i]为白色
            paint('B', i+1, j+1);  // [i+1, j]为蓝色
            paint('R', j+1, n);    // [j+1, n-1]为红色
            minChanges = min(minChanges, changes);
        }
    }
    
    cout << minChanges << endl;
    return 0;
}