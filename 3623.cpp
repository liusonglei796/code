#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int>v(15);
vector<bool>used(15);  // 记录数字是否被使用

void dfs(int pos,int k){
    if(pos==k){
        for(int i=0;i<k;++i){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;++i){
        if(!used[i]){  // 只使用未使用过的数字
            used[i]=true;
            v[pos]=i;
            dfs(pos+1,k);
            used[i]=false;  // 回溯时恢复状态
        }
    }
}

int main() {
    cin>>n>>k;
    dfs(0,k);
    return 0;
}

