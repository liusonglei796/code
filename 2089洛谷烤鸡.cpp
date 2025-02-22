#include<bits/stdc++.h>

using namespace std;
vector<int>v1(10);
vector<vector<int>>v2;
int n;
void dfs(int pos, int sum) {
    if (pos == 9) {  // 修正：先判断终止条件
        if (sum == n) {
            v2.emplace_back(v1);
        }
        return;  // 移到这里，确保pos==9时一定返回
    }
    
    for(int i = 1; i <= 3; ++i) {
        if(sum + i + (9 - pos) > n) continue;  // 剪枝：最大情况
        if(sum + i + (9 - pos) * 3 < n) continue;  // 剪枝：最小情况
        v1[pos] = i;
        dfs(pos + 1, sum + i);
    }
}

int main(){
cin>>n;
dfs(0,0);
cout<<v2.size()<<'\n';
for(auto it:v2)
{
for(auto it2:it){
    cout<<it2<<" ";
}
cout<<'\n';

}
    return 0;
}