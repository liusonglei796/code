#include <iostream>
// 假设这是存储数据的结构体
struct Node {
    int val;
    int num;
};
Node a[10000]; // 假设数组大小足够，你可以根据实际情况调整

int main() {
    int n;
    std::cin >> n;
    int t = 1;
    // 从 2^n 到 2^(n + 1) - 1 输入数据并设置编号
    for(int i = (1<<n); i < (1<<(n+1)); i++){
        std::cin >> a[i].val;
        a[i].num = t;
        t++;
    }
    // 从 2^n - 1 到 2 进行某种比较和赋值操作（可能是二叉树的某种处理）
    for(int i = (1<<n) - 1; i > 1; i--){
        if(a[i*2].val > a[i*2+1].val) a[i] = a[i*2];
        else a[i]= a[i*2+1];
    }
    // 比较 a[2] 和 a[3] 的 val 值，并输出相应的 num
    if(a[2].val < a[3].val) std::cout << a[2].num;
    else std::cout << a[3].num;
    return 0;
}