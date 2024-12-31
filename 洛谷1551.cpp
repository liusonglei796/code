#include <iostream>
using namespace std;

const int MAXN = 5000 + 5;
int parent[MAXN];  // 存储每个节点的父节点

// 初始化并查集，每个节点的父节点初始化为自己
void init(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
}

// 查找x所在集合的根节点（带路径压缩）
int find(int x) {
    return x == parent[x]? x : parent[x] = find(parent[x]);
}

// 合并x和y所在的集合
void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX!= rootY) {
        parent[rootX] = rootY;
    }
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    init(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        unionSet(a, b);
    }
    for (int i = 0; i < p; ++i) {
        int x, y;
        cin >> x >> y;
        if (find(x) == find(y)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}