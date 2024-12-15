#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k, x, y, o, p, ans = 0;
int dx1[13] = {2, 0, -2, 0, 1, 1, 1, 0, 0, 0, -1, -1, -1},
    dy1[13] = {0, 2, 0, -2, 0, 1, -1, 1, 0, -1, 0, 1, -1};
int dx2[25] = {-2, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2},
    dy2[25] = {-2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2};

int main() {
    cin >> n >> m >> k;
    int a[n + 5][n + 5];
    std::fill(&a[0][0], &a[0][0] + (n + 5) * (n + 5), 0);

    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        for (int j = 0; j < 13; j++) {
            int new_x = x + dx1[j];
            int new_y = y + dy1[j];
            if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= n) {
                a[new_x][new_y] = 1;
            }
        }
    }

    for (int i = 1; i <= k; i++) {
        cin >> o >> p;
        for (int j = 0; j < 25; j++) {
            int new_x = o + dx2[j];
            int new_y = p + dy2[j];
            if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= n) {
                a[new_x][new_y] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= 1 && i <= n && j >= 1 && j <= n && a[i][j] == 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}