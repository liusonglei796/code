#include <bits/stdc++.h>  // 包含标准库
using namespace std;

int main() {
    int n, r;  // n为总数字个数，r为每组选择的数字个数
    cin >> n >> r;  // 输入n和r
    
    // 创建大小为n的标记数组，初始全为0
    vector<int> mark(n, 0);
    // 将前r个位置设置为1，表示初始选中状态
    for(int i = 0; i < r; i++) {
        mark[i] = 1;
    }
    
    // 使用prev_permutation生成所有可能的组合
    do {
        int count = 0;  // 记录当前已输出的数字个数
        // 遍历标记数组，输出被选中的数字
        for(int i = 0; i < n && count < r; i++) {
            if(mark[i]) {  // 如果当前位置被标记为选中
                cout << setw(3) << i + 1;  // 输出对应的数字，占据3个字符宽度
                count++;  // 已输出数字计数加1
            }
        }
        cout << endl;  // 每个组合输出完成后换行
    } while(prev_permutation(mark.begin(), mark.end()));  // 生成前一个排列，直到最小排列
    
    return 0;  // 程序结束
}