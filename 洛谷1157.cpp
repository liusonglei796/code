#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// 深度优先搜索函数，用于生成组合
void dfs(int n, int r, int start, vector<int>& combination, int index) {
    if (index == r) {
        for (int num : combination) {
            cout << setw(3) << num;
        }
        cout << endl;
        return;
    }
    for (int i = start; i <= n; i++) {
        combination[index] = i;
        dfs(n, r, i + 1, combination, index + 1);
    }
}

int main() {
    int n, r;
    cin >> n >> r;
    vector<int> combination(r);
    dfs(n, r, 1, combination, 0);
    return 0;
}