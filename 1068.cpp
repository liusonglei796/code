#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct attribute {
    int id;
    int s;
};

bool comp(attribute a, attribute b) {
    if (a.s != b.s) return a.s > b.s;
    return a.id < b.id;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<attribute> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].id >> v[i].s;
    }

    int index = floor(m * 1.5);
    sort(v.begin(), v.end(), comp);

    int actualCount = 0;
    int actualScoreLine = v[index - 1].s; // 初始假设

    // 计算实际录取人数和实际分数线
    for (int i = 0; i < n; ++i) {
        if (v[i].s >= actualScoreLine) {
            actualCount++;
        } else {
            break;
        }
    }
    // 重新计算实际录取分数线，以防同分情况。
    actualScoreLine = v[actualCount - 1].s;

    cout << actualScoreLine << " " << actualCount << endl;

    for (int i = 0; i < actualCount; ++i) {
        cout << v[i].id << " " << v[i].s << endl;
    }

    return 0;
}