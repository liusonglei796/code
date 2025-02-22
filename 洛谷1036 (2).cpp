#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int>v1;
vector<bool>used;  // 标记数字是否被使用

bool isPrime(int num) {
    if(num < 2) return false;
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

void dfs(int sum, int &count, int pos, int k) {
    if(k == 0) {
        if(isPrime(sum)) {
            count++;
        }
        return;
    }
    for(int i = pos; i < n; i++) {
        //used数组在这个问题中其实是多余的，因为通过pos的控制已经保证了不会重复选择
        //pos参数保证了我们只会向后选择数字，永远不会重复选择前面的数字
//每次递归时i + 1作为新的pos传入，确保下一层递归只能选择当前数字之后的数字
        /*举个例子，假设输入序列是[1,2,3]，要选择2个数：
第一次选1，然后只能从2,3中选
第一次选2，然后只能从3选
第一次选3，没有更多数字可选*/
        if(!used[i]) {
            used[i] = true;  // 标记使用
            dfs(sum + v1[i], count, i + 1, k - 1);
            used[i] = false; // 回溯，取消标记
        }
    }
}

int main() {
    cin >> n >> k;
    v1.resize(n);
    used.resize(n, false);  // 初始化标记数组
    for(int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    int count = 0;
    dfs(0, count, 0, k);
    cout << count << endl;
    return 0;
}