#include<bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int n) : parent(n + 1) {
        for(int i = 1; i <= n; i++) parent[i] = i;
    }
    
    int find(int x) {
        return parent[x] == x? x : (parent[x] = find(parent[x]));
    }
    
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    UnionFind friends(n);
    vector<vector<int>> enemy(n + 1);
    
    for(int i = 0; i < m; i++) {
        char op;
        int x, y;
        cin >> op >> x >> y;
        
        if(op == 'F') {
            friends.unite(x, y);
        } else {  // op == 'E'
            enemy[x].push_back(y);
            enemy[y].push_back(x);
            
            // 敌人的敌人是朋友
            for(int e : enemy[x]) {
                if(e!= y) friends.unite(e, y);
            }
            for(int e : enemy[y]) {
                if(e!= x) friends.unite(e, x);
            }
        }
    }
    
    // 统计不同集合的数量
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(friends.find(i) == i){
            count++;
        }
    }
    
    cout << count;
    return 0;
}