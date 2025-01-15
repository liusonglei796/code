#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    
    // 创建计数数组，下标表示和，值表示出现次数
    vector<int> count(s1 + s2 + s3 + 1);
    
    // 统计所有可能的和的出现次数
    for(int i = 1; i <= s1; i++)
        for(int j = 1; j <= s2; j++)
            for(int k = 1; k <= s3; k++)
                count[i + j + k]++;
    
    // 找出出现次数最多的和
    int max_freq = 0, ans = 0;
    for(int i = 3; i <= s1 + s2 + s3; i++){
        if(count[i] > max_freq){
            max_freq = count[i];
            ans = i;
        }
    }
    
    cout << ans << endl;
    return 0;
}