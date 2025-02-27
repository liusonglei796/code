#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

// 修改图的定义为二维vector
vector<vector<int>> graph(MAXN);
bool visited[MAXN];

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";
    
    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}
void bfs(int start) {
    queue<int> q;
    fill(visited, visited + MAXN, false);
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        
        for (int next : graph[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // 建图
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        //std::vector是C++标准库中的动态数组，它不仅可以存储单个数据类型，还可以存储复杂的数据结构，比如数组、列表、对象等。
        //每个std::vector<int>可以存储多个整数，表示从某个节点出发的所有邻接节点。
        graph[x].push_back(y);
    }
    
    // 对每个节点的邻接表排序，保证按编号从小到大访问
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    
    // DFS遍历
    fill(visited, visited + MAXN, false);
    dfs(1);
    cout << endl;
    
    // BFS遍历
    bfs(1);
    cout << endl;
    
    return 0;
}
