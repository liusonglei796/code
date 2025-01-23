#include <bits/stdc++.h>         // 包含所有标准库
using namespace std;

int main() {
    string n;                    // 存储输入的高精度数字
    int k;                       // 需要删除的数字个数
    cin >> n >> k;               // 读入数字和k
    
    string result = n;           // 创建副本进行操作
    while(k--) {                 // 循环k次，每次删除一个数字
        int i;                   // 用于记录要删除的位置
        // 从左到右找第一个比右边大的数字（这样删除后能保证最小）
        for(i = 0; i < result.size()-1; i++) {
            if(result[i] > result[i+1]) {  // 找到一个比右边大的数字
                break;                      // 找到后立即退出
            }
        }
        // 如果没找到比右边大的数字（即数字序列递增）
        if(i == result.size()-1) {
            result.pop_back();    // 删除最后一个数字
        } else {
            result.erase(result.begin() + i);  // 删除找到的那个数字
        }
    }
    
    // 删除结果中的前导零
    while(result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());  // 删除开头的0
    }
    
    cout << result << "\n";      // 输出最终结果
    return 0;                    // 程序结束
}