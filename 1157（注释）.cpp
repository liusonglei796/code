#include<bits/stdc++.h>
using namespace std;

int n, r;
vector<int> b;

void dfs(int pos, int start) {
    if (pos == r) {
        for (int i = 0; i < r; i++) {
            printf("%3d", b[i]);
        }
        printf("\n");
        return;
    }
    //只用used数组而不用start参数确实不能保证升序。我来解释一下原因：
    // 假设 n=3, r=2，如果只用used数组而不限制起始位置，会出现这样的情况：
      //1. 当pos=0时，可以选择1,2,3任意数字  
      //2. 当pos=1时，也可以选择除了已用数字外的任何数字  比如这样的过程： • 第一个位置选1，第二个位置可以选2,3 -> [1,2], [1,3]  • 第一个位置选2，第二个位置可以选1,3 -> [2,1], [2,3] 
      // 这里出现了[2,1]，不是升序  • 第一个位置选3，第二个位置可以选1,2 -> [3,1], [3,2] // 这里出现了[3,1], [3,2]，不是升序  所以只用used数组会生成所有可能的排列，而不是升序的组合。
      // 而使用start参数后： • 第一个位置(pos=0)从1开始，可以选择1,2,3  • 如果第一个位置选了1，第二个位置只能从2开始选  • 如果第一个位置选了2，第二个位置只能从3开始选  • 如果第一个位置选了3，第二个位置没有可选数字（因为必须>3）  这样就自然保证了生成的序列一定是升序的。
    for (int i = start; i <= n; i++) {
        b[pos] = i;
        dfs(pos + 1, i + 1);
    }
}

int main() {
    cin >> n >> r;
    b.resize(r);
    dfs(0, 1);
    return 0;
}
