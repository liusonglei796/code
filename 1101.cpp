#include <iostream> 
#include <vector> 
using namespace std; 
 
const int MAXN = 105; 
const string target = "yizhong"; 
int n; 
char grid[MAXN][MAXN]; 
bool isPartOfWord[MAXN][MAXN]; 
 
// 八个方向的偏移量 
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; 
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; 
 
// 检查从 (x, y) 开始，沿着方向 d 是否能找到单词 "yizhong" 
bool check(int x, int y, int d) { 
    for (int i = 0; i < target.length();  i++) { 
        int nx = x + i * dx[d]; 
        int ny = y + i * dy[d]; 
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] != target[i]) { 
            return false; 
        } 
    } 
    return true; 
} 
 
// 标记从 (x, y) 开始，沿着方向 d 的单词 "yizhong" 
void mark(int x, int y, int d) { 
    for (int i = 0; i < target.length();  i++) { 
        int nx = x + i * dx[d]; 
        int ny = y + i * dy[d]; 
        isPartOfWord[nx][ny] = true; 
    } 
} 
 
int main() { 
    cin >> n; 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            cin >> grid[i][j]; 
            isPartOfWord[i][j] = false; 
        } 
    } 
 
    // 遍历每个位置，检查是否能找到单词 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            if (grid[i][j] == 'y') { 
                for (int d = 0; d < 8; d++) { 
                    if (check(i, j, d)) { 
                        mark(i, j, d); 
                    } 
                } 
            } 
        } 
    } 
 
    // 输出结果 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            if (isPartOfWord[i][j]) { 
                cout << grid[i][j]; 
            } else { 
                cout << '*'; 
            } 
        } 
        cout << endl; 
    } 
 
    return 0; 
} 