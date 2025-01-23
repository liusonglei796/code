#include<bits/stdc++.h>  // 包含所有标准库
using namespace std;

// 将连续三个数字转换为三位数
int toNum(vector<int>& v, int start) {
    return v[start] * 100 + v[start + 1] * 10 + v[start + 2];  // 计算三位数
}

int main() {
    int a, b, c;  // 存储三个数的比例
    cin >> a >> b >> c;  // 输入比例值
    
    vector<int> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};  // 存储1-9九个数字
    vector<vector<int>> solutions;  // 存储所有满足条件的解
    
    do {
        int num1 = toNum(digits, 0);  // 获取第一个三位数
        int num2 = toNum(digits, 3);  // 获取第二个三位数
        int num3 = toNum(digits, 6);  // 获取第三个三位数
        
        // 检查这三个数是否满足比例关系 a:b:c
        if(num2 * a == num1 * b && num3 * a == num1 * c) {
            solutions.push_back({num1, num2, num3});  // 将满足条件的解加入结果集
        }
    } while(next_permutation(digits.begin(), digits.end()));  // 生成下一个排列
    
    if(solutions.empty()) {  // 如果没有找到解
        cout << "No!!!\n";  // 输出No!!!
        return 0;
    }
    
    sort(solutions.begin(), solutions.end());  // 按第一个数字升序排序所有解
    
    // 输出所有解
    for(const auto& solution : solutions) {  // 遍历每个解
        cout << solution[0] << " " << solution[1] << " " << solution[2] << "\n";  // 输出三个数字
    }
    
    return 0;  // 程序正常结束
}