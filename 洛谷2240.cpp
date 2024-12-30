#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

// 定义结构体表示每堆金币的重量、价值和单位价值
typedef struct price {
    int m;  // 重量
    int v;  // 价值
    double uniteprice;  // 单位价值（价值/重量）
} price;

// 比较函数，用于按照单位价值从大到小排序
bool compare(price a, price b) {
    return a.uniteprice > b.uniteprice;
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<price> v(n);
    // 输入每堆金币的重量和价值，并计算单位价值
    for (int i = 0; i < n; ++i) {
        cin >> v[i].m;
        cin >> v[i].v;
        v[i].uniteprice = static_cast<double>(v[i].v) / v[i].m;  // 这里要先将v[i].v转换为double类型再做除法，修正计算单位价值的方式
    }

    double sum = 0;
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; ++i) {
        if (t >= v[i].m) {
            t -= v[i].m;
            sum += v[i].v;
        }
        else {
            sum += v[i].uniteprice * t;  // 这里修改计算逻辑，应该是单位价值乘剩余重量
            break;
        }
    }

    cout << fixed << setprecision(2) << sum << endl;  // 设置精度输出需要加上fixed，并且最后要输出换行符
    return 0;
}