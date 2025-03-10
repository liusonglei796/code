#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<bool> visited;
vector<int> v;
int cnt = 0;
int sum = 0;  // 改为全局变量

bool isprime(int x) {
    if(x <= 1) return false;
    if(x == 2) return true;
    for(int i = 2; i <= sqrt(x); ++i) {
        if(x % i == 0) return false;
    }
    return true;
}

void dfs(int pos, int start) {  // 移除sum参数
    if(pos == k) {
        if(isprime(sum)) {
            cnt++;
        }
        return;
    }
    
    for(int i = start; i < n; ++i) {
        if(!visited[i]) {
            visited[i] = true;
            sum += v[i];        // 加入当前数
            dfs(pos + 1, i + 1);
            sum -= v[i];        // 回溯时减去
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> k;
    v.resize(n);
    visited.resize(n, false);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    dfs(0, 0);  // 移除sum参数
    cout << cnt << endl;
    
    return 0;
}