#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>mp;
int n,c;

int main(){
    cin>>n>>c;
    // 读入数据并统计每个数字出现的次数
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        mp[x]++;
    }
    
    long long cnt=0;  // 改用long long防止溢出
    // 对于每个数x，寻找满足x-(x-c)=c的数对
    for(auto it:mp){
        int x = it.first;
        // 在map中查找x-c
        if(mp.find(x-c)!=mp.end()){
            // 将当前数的出现次数与(x-c)的出现次数相乘
            cnt += (long long)it.second * mp[x-c];
        }
    }
    cout<<cnt;
    return 0;
}