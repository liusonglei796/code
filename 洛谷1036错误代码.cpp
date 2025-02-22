#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int>v1;

bool isPrime(int num) {
    if(num < 2) return false;
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}
//隐式回溯：通过函数参数传递新状态，函数返回时自动恢复旧状态
//显式回溯：明确地标记和修改状态，然后手动恢复状态
//在这道题中，由于我们只需要记录sum，而sum是通过参数传递的，所以不需要显式回溯。如果需要维护一个选择的路径或者需要标记已使用的元素，显式回溯会更有用。
void dfs(int sum, int &count, int k) {
    if(k == 0) {
        if(isPrime(sum)) {
            count++;
        }
        return;
    }
    
    // 直接遍历所有数字，不考虑位置
    for(int i = 0; i < n; i++) {
        dfs(sum + v1[i], count, k - 1);
    }
}

int main() {
    cin >> n >> k;
    v1.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    int count = 0;
    dfs(0, count, k);
    cout << count << endl;
    return 0;
}