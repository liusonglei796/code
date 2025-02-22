#include<bits/stdc++.h>
using namespace std;
// n: 可选数字的范围(1到n)
// r: 需要选择的数字个数
int n, r;
// b: 存储当前组合的数组
vector<int> b;
/**
 * 深度优先搜索生成组合数
 * @param pos 当前要填充的位置
 * @param num 已经选择的数字个数
 * @param last 上一个选择的数字，用于保证升序
 */
void dfs(int pos, int num, int last) {
    // 当已选择的数字个数等于要求的个数时，输出当前组合
    if (num == r) {
        for (int i = 0; i < r; i++) {
            cout << setw(3) << b[i];
        }
        cout << endl;
        return;
    }

    for (int i = last; i <= n; ++i) {
        b[pos] = i;
        dfs(pos + 1, num + 1, i + 1);
    }
}

int main() {
    // 输入n和r的值
    cin >> n >> r;
    // 初始化存储空间
    b.resize(r);
    // 从第0个位置开始，已选择0个数字
    dfs(0, 0, 1);
    return 0;
}