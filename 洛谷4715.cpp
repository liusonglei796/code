#include<bits/stdc++.h>
using namespace std;

struct Team {
    int strength, index;
};

int main() {
    int n;
    cin >> n;
    
    int size = 1 << (n + 1);  // 树的总节点数为2^(n+1)
    vector<Team> tree(size);   // 用数组表示完全二叉树
    
    // 读入初始队伍数据，存储在树的叶子节点
    int leaf_start = 1 << n;  // 第一个叶子节点的位置
    for(int i = 1; i <= (1 << n); i++) {
        int strength;
        cin >> strength;
        tree[leaf_start + i - 1] = {strength, i};
    }
    
    int runner_up = 0;
    // 从倒数第二层开始向上模拟比赛
    for(int i = leaf_start - 1; i > 0; i--) {
        int left = 2 * i, right = 2 * i + 1;
        if(tree[left].strength > tree[right].strength) {
            tree[i] = tree[left];
            if(i == 1) runner_up = tree[right].index;  // 决赛败者
        } else {
            tree[i] = tree[right];
            if(i == 1) runner_up = tree[left].index;   // 决赛败者
        }
    }
    
    cout << runner_up << "\n";
    return 0;
}
