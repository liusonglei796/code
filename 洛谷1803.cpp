#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

// 定义结构体表示比赛的开始时间和结束时间
struct Contest {
    int start;
    int end;
};

// 比较函数，用于按照比赛结束时间从小到大排序
bool compare(Contest a, Contest b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    vector<Contest> contests(n);
    // 输入每个比赛的开始时间和结束时间
    for (int i = 0; i < n; ++i) {
        cin >> contests[i].start;
        cin >> contests[i].end;
    }

    // 按照比赛结束时间对所有比赛进行排序
    sort(contests.begin(), contests.end(), compare);

    int count = 0;  // 记录能够参加的比赛数量
    int current_end = -1;  // 当前已经选择的比赛的结束时间，初始化为一个较小值

    for (int i = 0; i < n; ++i) {
        if (contests[i].start >= current_end) {
            count++;
            current_end = contests[i].end;
        }
    }

    cout << count << endl;
    return 0;
}
