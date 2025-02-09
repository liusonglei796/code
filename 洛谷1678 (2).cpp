#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> v1;  // 存储学校分数线
vector<int> v2;  // 存储学生估分

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    v1.resize(m);
    v2.resize(n);
    
    // 输入学校分数线和学生估分
    for(int i = 0; i < m; i++) {
        cin >> v1[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> v2[i];
    }
    
    // 对学校分数线排序，方便二分查找
    sort(v1.begin(), v1.end());
    
    long long total = 0;  // 总不满意度
    
    // 对每个学生找最接近的学校分数线
    for(int i = 0; i < n; i++) {
        // 找到第一个大于等于学生分数的位置
        auto it = lower_bound(v1.begin(), v1.end(), v2[i]);
        
        if(it == v1.begin()) {
            // 如果是第一个位置，直接计算差值
            total += abs(*it - v2[i]);
        }
        else if(it == v1.end()) {
            // 如果超出范围，用最后一个分数线计算
            total += abs(v1.back() - v2[i]);
        }
        else {
            // 否则，需要比较当前位置和前一个位置，取较小值
            total += min(abs(*it - v2[i]), abs(*(it-1) - v2[i]));
        }
    }
    
    cout << total << endl;
    return 0;
}