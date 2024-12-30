#include <iostream>
#include <algorithm>
using namespace std;

// 假设存在这样一个结构体
struct Person {
    int time;
    int num;
};

// 比较函数
bool cmp(const Person& a, const Person& b) {
    return a.time < b.time;
}

int main() {
    int n;
    cin >> n;
    Person ps[n + 1];
    // 输入每个人接水所需时间并编号
    for (int i = 1; i <= n; i++) {
        cin >> ps[i].time;
        ps[i].num = i;
    }
    // 按照接水时间排序
    sort(ps + 1, ps + n + 1, cmp);
    double sum = 0;
    // 输出排序后的编号并计算总等待时间
    for (int i = 1; i <= n; i++) {
        cout << ps[i].num << " ";
        sum += (n - i) * ps[i].time;
    }
    cout << endl;
    double avg = sum / n;
    // 输出平均等待时间，保留两位小数
    printf("%.2f", avg);
    return 0;
}

