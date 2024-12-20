#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Toy {
    bool direction;
    string job;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Toy> toys(n);
    for (int i = 0; i < n; ++i) {
        int dir;
        string job;
        cin >> dir >> job;
        toys[i].direction = dir;
        toys[i].job = job;
    }

    int cur = 0;
    for (int i = 0; i < m; ++i) {
        int dir, num;
        cin >> dir >> num;
        if (dir == 0) {
            // 向左数
            if (toys[cur].direction == 0) {
                cur = (cur + n - num) % n;
            } else {
                cur = (cur + num) % n;
            }
        } else {
            // 向右数
            if (toys[cur].direction == 0) {
                cur = (cur + num) % n;
            } else {
                cur = (cur + n - num) % n;
            }
        }
    }
    cout << toys[cur].job << endl;
    return 0;
}