#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    
    int num = 1;
    int left = 0, right = n-1, top = 0, bottom = n-1;
    
    while(num <= n*n){
        // 从左到右
        for(int i = left; i <= right; i++)
            v[top][i] = num++;
        top++;
        
        // 从上到下
        for(int i = top; i <= bottom; i++)
            v[i][right] = num++;
        right--;
        
        // 从右到左
        for(int i = right; i >= left; i--)
            v[bottom][i] = num++;
        bottom--;
        // 从下到上
        for(int i = bottom; i >= top; i--)
            v[i][left] = num++;
        left++;
    }
    
    // 格式化输出
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << setw(3) << v[i][j];
        }
        cout << endl;
    }
    
    return 0;
}