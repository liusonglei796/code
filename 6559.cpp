#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    unordered_set<long long> houses;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        houses.insert((long long)x * (n + 2) + y); // 使用一个唯一的键来存储坐标
    }
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int total = 0;
    
    for (auto it = houses.begin(); it != houses.end(); ++it) {
        long long pos = *it;
        int x = pos / (n + 2);
        int y = pos % (n + 2);
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (houses.count((long long)nx * (n + 2) + ny)) {
                total++;
            }
        }
    }
    
    cout << total / 2 << endl;
    return 0;
}