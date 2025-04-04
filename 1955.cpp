#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int MAXN = 1e5 + 5;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

bool solve() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> neq;  // 存储不等关系
    unordered_map<int, int> id;  // 离散化
    int cnt = 0;
    
    // 读取所有关系并处理等式关系
    vector<tuple<int, int, int>> relations(n);
    for(int i = 0; i < n; i++) {
        int x, y, e;
        cin >> x >> y >> e;
        relations[i] = {x, y, e};
        
        // 离散化处理
        if(id.find(x) == id.end()) id[x] = cnt++;
        if(id.find(y) == id.end()) id[y] = cnt++;
    }
    
    UnionFind uf(cnt);
    
    // 首先处理所有等式
    for(auto [x, y, e] : relations) {
        if(e == 1) {
            uf.unite(id[x], id[y]);
        }
    }
    
    // 然后检查所有不等式是否有矛盾
    for(auto [x, y, e] : relations) {
        if(e == 0) {
            if(uf.same(id[x], id[y])) {
                return false;  // 发现矛盾
            }
        }
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
    return 0;
}