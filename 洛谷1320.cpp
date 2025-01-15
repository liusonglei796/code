#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    vector<string> matrix;
    
    // 读取矩阵
    while(cin >> s){
        matrix.push_back(s);
    }
    
    int n = matrix[0].size();
    cout << n << " ";
    
    // 将矩阵转为一维字符串
    string all = "";
    for(const auto& row : matrix){
        all += row;
    }
    
    // 统计连续的0和1
    // 先输出开头的0的个数
    int zeros = 0;
    while(zeros < all.size() && all[zeros] == '0') zeros++;
    cout << zeros << " ";
    
    // 统计剩余的连续数字
    if(zeros < all.size()){
        int count = 1;
        for(int i = zeros + 1; i < all.size(); i++){
            if(all[i] == all[i-1]){
                count++;
            } else {
                cout << count << " ";
                count = 1;
            }
        }
        cout << count;  // 输出最后一组
    }
    
    return 0;
}