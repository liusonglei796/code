#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
bool exist[MAXN];        // 判断编号是否在队列中
list<int> q;            // 存储队列
list<int>::iterator pos[MAXN];  // 存储每个编号在list中的位置

int main() {
    int n, m;
    cin >> n;
    
    // 初始化1号位置
    q.push_back(1);
    exist[1] = true;
    pos[1] = q.begin();
    
    // 处理插入
    for (int i = 2; i <= n; i++) {
        int k, p;
        cin >> k >> p;
        exist[i] = true;
        
        if (p == 0) {  // 插入左边
            pos[i] = q.insert(pos[k], i);
        } else {       // 插入右边
            auto it = next(pos[k]);
            pos[i] = q.insert(it, i);
        }
    }
    
    // 处理删除
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        if (exist[x]) {
            exist[x] = false;
            q.erase(pos[x]);
        }
    }
    
    // 输出结果
    for (int x : q) {
        cout << x << " ";
    }
    
    return 0;
}