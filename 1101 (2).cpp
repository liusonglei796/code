#include <bits/stdc++.h>
using namespace std;

const string target = "yizhong";
int n;
vector<string> grid;
vector<vector<bool>> marked;  // 标记需要显示的字符

// 8个方向：右、左、下、上、右下、左下、右上、左上
const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int main() {
    cin >> n;
    grid.resize(n);
    marked.resize(n, vector<bool>(n, false));
    
    // 读取网格
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    
    // 遍历网格寻找'y'
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'y') {
                // 检查8个方向
                for (int dir = 0; dir < 8; ++dir) {
                    bool match = true;
                    // 检查整个单词
                    for (int k = 1; k < target.size(); ++k) {
                        int ni = i + dx[dir] * k;
                        int nj = j + dy[dir] * k;
                        // 检查边界和字符匹配
                        if (ni < 0 || ni >= n || nj < 0 || nj >= n || 
                            grid[ni][nj] != target[k]) {
                            match = false;
                            break;
                        }
                    }
                    // 如果找到匹配，标记所有字符
                    if (match) {
                        for (int k = 0; k < target.size(); ++k) {
                            int ni = i + dx[dir] * k;
                            int nj = j + dy[dir] * k;
                            marked[ni][nj] = true;
                        }
                    }
                }
            }
        }
    }
    
    // 输出结果
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (marked[i][j] ? grid[i][j] : '*');
        }
        cout << endl;
    }
    
    return 0;
}