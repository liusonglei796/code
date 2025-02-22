#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int>v1;
vector<int>path;  // 存储选择的数

bool isPrime(int num) {
    if(num < 2) return false;
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

void dfs(int &count, int pos, int k) {
    if(k == 0) {
        int sum = 0;
        for(int x : path) sum += x;  // 计算选中数字的和
        if(isPrime(sum)) {
            count++;
        }
        return;
    }
    
    for(int i = pos; i < n; i++) {
        
        path.push_back(v1[i]);       // 1. 选择：将当前数加入路径
        dfs(count, i + 1, k - 1);    // 2. 探索：继续搜索下一个数
        path.pop_back();             // 3. 回溯：将当前数移除，恢复现场// 假设输入：n=4, k=2, 数组为[1,2,3,4]
//当k=2时，整个DFS过程会是这样:
//选择1,2: path=[1,2] -> 检查和是否为质数 -> 回溯移除2
//选择1,3: path=[1,3] -> 检查和是否为质数 -> 回溯移除3
//选择1,4: path=[1,4] -> 检查和是否为质数 -> 回溯移除4
//回溯移除1
//选择2,3: path=[2,3] -> 检查和是否为质数 -> 回溯移除3
//...以此类推
    }
}

int main() {
    cin >> n >> k;
    v1.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    int count = 0;
    dfs(count, 0, k);
    cout << count << endl;
    return 0;
}