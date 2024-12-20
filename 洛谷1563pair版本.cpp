#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // 使用vector<pair<int, string>>来存储玩具小人信息
    // pair的第一个元素表示方向，第二个元素表示职业
    vector<pair<int, string>> toys(n);
    for (int i = 0; i < n; ++i) {
        int dir;
        string job;
        cin >> dir >> job;
        toys[i] = make_pair(dir, job);
    }

    int cur = 0;
    for (int i = 0; i < m; ++i) {
        int dir, num;
        cin >> dir >> num;
        if (dir == 0) {
            // 向左数
            if (toys[cur].first == 0) {
                cur = (cur + n - num) % n;
            } else {
                cur = (cur + num) % n;
            }
        } else {
            // 向右数
            if (toys[cur].first == 0) {
                cur = (cur + num) % n;
            } else {
                cur = (cur + n - num) % n;
            }
        }
    }
    // 输出最终到达的玩具小人的职业
    cout << toys[cur].second << endl;
    return 0;
}