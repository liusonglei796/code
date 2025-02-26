#include<bits/stdc++.h>
using namespace std;
list<int>lt;
int n,m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    // 初始化1到n的数字
    for(int i=1;i<=n;++i){
        lt.emplace_back(i);
    }
    
    auto it = lt.begin();
    while(!lt.empty()){
        // 数到m-1次(因为从当前位置开始)
        for(int i=1;i<m;++i){
            ++it;
            if(it == lt.end()) it = lt.begin();
        }
        // 输出并删除第m个数
        cout<<*it<<" ";
        it = lt.erase(it);
        if(it == lt.end()) it = lt.begin();
    }
    
    return 0;
}