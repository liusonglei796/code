#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    //通过反向建图和从大到小处理点，确保每个点只被访问一次
    // 反向建图
    vector<vector<int>> rev(n+1);
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        // 反向存边
        rev[y].push_back(x);
    }
    
    // ans[i]表示从点i能到达的最大编号
    vector<int> ans(n+1, 0);
    
    // 初始时，每个点能到达的最大编号就是自己
    for(int i = 1; i <= n; ++i){
        ans[i] = i;
    }
    //对于每个点i，我们找出所有能到达i的点，这些点能到达的最大编号至少是i
    //所以 从大到小遍历每个点
    vector<bool> visited(n+1, false);
    for(int i = n; i >= 1; --i){
        if(!visited[i]){
            // BFS从点i开始
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                // 从i能到达的点cur，那么cur能到达的最大编号就是i
                ans[cur] = max(ans[cur], i);
                // 遍历所有能到达cur的点
                for(auto prev : rev[cur]){
                    if(!visited[prev]){
                        visited[prev] = true;
                        q.push(prev);
                        // 从prev能到达的最大编号至少是i
                        ans[prev] = i;
                    }
                }
            }
        }
    }
    // 输出结果
    for(int i = 1; i <= n; ++i){
        cout << ans[i] << " ";
    }
    
    return 0;
}