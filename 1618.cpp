#include<bits/stdc++.h>
using namespace std;
int a, b, c;
vector<int> path(9);  // 当前路径
vector<vector<int>> ans;
bool used[10];     // 记录数字1-9的使用情况
void dfs(int depth) {    
if(depth == 9) {  // 收集到9个数字        
int n1 = path[0]*100 + path[1]*10 + path[2];        
int n2 = path[3]*100 + path[4]*10 + path[5];        
int n3 = path[6]*100 + path[7]*10 + path[8];                
if(n1 * b == n2 * a && n1 * c == n3 * a) {            
ans.push_back({n1, n2, n3});        
}        
return;    
}        
for(int i = 1; i <= 9; i++) {        
if(!used[i]) {            
used[i] = true;          
path[depth]=i;            //如果不用used标记：                          //第一个位置用了1第二个位置还可能用1（这是不合法的，因为每个数字只能用一次）
dfs(depth + 1);                     
used[i] = false;        
}    
}
}
int main() {    
cin >> a >> b >> c;    
memset(used, 0, sizeof(used));        
dfs(0);        
if(ans.empty()) {        
cout << "No!!!" << endl;    
} else {        
for(const auto& v : ans) {            
cout << v[0] << " " << v[1] << " " << v[2] << endl;        
}    
}    
return 0;
}