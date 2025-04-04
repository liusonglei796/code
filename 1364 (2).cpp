#include <bits/stdc++.h>
using namespace std;

struct tree {
    int val;
    int left;
    int right;
    int parent;
};

vector<tree> v(105);
int n;
long long ans = LLONG_MAX;

void bfs(int start, long long &sum) {
    vector<int> steps(n + 1, -1);  // 记录每个节点的步数
    queue<int> q;
    q.push(start);
    steps[start] = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        sum += steps[node] * v[node].val;
        
        // 处理左孩子
        if (v[node].left && steps[v[node].left] == -1) {
            steps[v[node].left] = steps[node] + 1;
            q.push(v[node].left);
        }
        // 处理右孩子
        if (v[node].right && steps[v[node].right] == -1) {
            steps[v[node].right] = steps[node] + 1;
            q.push(v[node].right);
        }
        // 处理父节点
        if (v[node].parent && steps[v[node].parent] == -1) {
            steps[v[node].parent] = steps[node] + 1;
            q.push(v[node].parent);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i].val >> v[i].left >> v[i].right;
        if (v[i].left) v[v[i].left].parent = i;
        if (v[i].right) v[v[i].right].parent = i;
    }

    for (int i = 1; i <= n; ++i) {
        long long sum = 0;
        bfs(i, sum);
        ans = min(ans, sum);
    }

    cout << ans;
    return 0;
}