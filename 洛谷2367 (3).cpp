#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000002; // 避免越界
int d[MAXN]; // d[i] 表示 a[i] - a[i-1]
int a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    // 输入初始成绩，并初始化差分数组
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        d[i] = a[i] - a[i - 1]; // 初始化差分数组
    }

    // 处理每个操作
    for (int i = 0; i < p; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        d[x] += z;       // 区间起点增加 z
        if (y + 1 <= n) {
            d[y + 1] -= z; // 区间终点后一个位置减少 z
        }
    }
//差分数组 d[] 记录了相邻元素之间的变化量。

//当我们对 d[x] 加上 z 时，相当于从位置 x 开始，a[x] 比 a[x - 1] 多了 z。

///由于 a[i] 是通过累加 d[i] 计算的，所以 x 之后的所有元素都会继承这个变化。
    /*ex:a[1]=a[0]+d[1];因为a[0]==0，所以a[1]=d[1];
      a[2]=a[1]+d[2]=d[1]+d[2];  
        a[3]=a[2]+d[3]=d[1]+d[2]+d[3];
        以此类推*/  
    // 计算最终成绩并找到最低分
    int min_score = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1] + d[i]; 
        if (a[i] < min_score) {
            min_score = a[i]; // 更新最低分
        }
    }

    // 输出结果
    cout << min_score << endl;

    return 0;
}