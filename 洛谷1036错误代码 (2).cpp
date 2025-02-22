#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int>v1;
vector<bool> visited;  // 添加visited数组

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
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {  // 只选择未使用过的数字
            visited[i] = true;  // 标记为已使用
            dfs(sum + v1[i], count, k - 1);
            visited[i] = false;  // 回溯，恢复未使用状态
        }
    }
}

int main() {
    cin >> n >> k;
    v1.resize(n);
    visited.resize(n, false);  // 初始化visited数组
    for(int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    int count = 0;
    dfs(0, count, k);
    cout << count << endl;
    return 0;
}

/*我看了一下代码，问题在于当前的实现会导致重复计数。让我解释一下问题并提供修复方案：
当前的问题：
当前的DFS会尝试从任何位置开始选择数字
这会导致相同的组合被多次计算，只是顺序不同
例如，如果有数字[1,2,3]要选择2个数，当前代码会把(1,2)和(2,1)算作两种不同情况
解决方案：
需要添加一个起始位置参数，确保我们只向前选择数字，避免重复组合。
实际上，由于我们已经通过start参数控制了选择的范围，visited数组就不需要了。这是更简化的版本：
这样修改后，代码会正确计算不同组合的数量，而不会重复计算。每个组合只会被统计一次，不管其中数字的选择顺序如何。
@https://www.luogu.com.cn/problem/P1036 @https://www.luogu.com.cn/problem/P1618 这两道题有啥区别吗，为啥这个代码不适用啊

让我解释一下这两道题的关键区别：
P1036 选数：
从n个数中选择k个数
要求这k个数的和是质数
同一个组合中的数字顺序不重要
例如：从[2,3,5]中选2个数，[2,3]和[3,2]算作同一种组合
P1618 三连击：
要求将1-9九个数字分成三组
每组形成一个三位数
数字的顺序很重要
例如：123和132是不同的三位数
当前代码的问题：
你的代码使用visited数组是为了防止同一个数字被重复使用，这是对的
但是它会把相同数字的不同排列都计算在内，这对P1036来说是错误的
修改建议：
主要改动：
移除了visited数组，因为我们不需要它
添加pos参数，只从当前位置往后选择，这样可以避免重复统计相同的组合
简化了代码结构
这样修改后，代码就能正确处理P1036的要求，只统计不同的组合而不考虑顺序。而对于P1618这种需要考虑顺序的题目，则需要使用visited数组的原始方案。*/