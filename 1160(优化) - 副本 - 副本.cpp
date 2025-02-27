#include<bits/stdc++.h>
using namespace std;
//使用数组记录每个数的位置，避免find操作
//改用双向链表配合数组来实现O(1)的插入和删除
const int MAXN = 100005;
list<int> lt;
vector<list<int>::iterator> iters(MAXN);  // 存储每个数对应的迭代器

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    lt.push_back(1);
    iters[1] = lt.begin();  // 记录1的位置
    
    for(int i=2; i<=n; ++i){
        int k, p;
        cin >> k >> p;
        auto it = iters[k];  // O(1)获取位置
        
        if(p == 0){
            iters[i] = lt.insert(it, i);
        }else{
            iters[i] = lt.insert(next(it), i);
        }
    }
    
    int m;
    cin >> m;
    while(m--){
        int x;
        cin >> x;
        if(iters[x] != lt.end()){  // 检查是否存在
            lt.erase(iters[x]);
            iters[x] = lt.end();  // 标记为已删除
        }
    }
    
    for(int x : lt){
        cout << x << ' ';
    }
    
    return 0;
}