#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    vector<int> P(M);
    for (int i = 0; i < M; ++i) {
        cin >> P[i];
    }
    
    vector<int> d(N + 2, 0);
    for (int i = 0; i < M - 1; ++i) {
        int s = P[i];
        int t = P[i + 1];
        int l = min(s, t);
        int r = max(s, t) - 1;
        if (l > r) continue;
        d[l]++;
        d[r + 1]--;
    }
    
    vector<long long> A(N + 1), B(N + 1), C(N + 1);
    for (int i = 1; i <= N - 1; ++i) {
        cin >> A[i] >> B[i] >> C[i];
    }
    
    long long ans = 0;
    int current = 0;
    for (int i = 1; i <= N - 1; ++i) {
        current += d[i];
        int k = current;
        long long cost1 = static_cast<long long>(k) * A[i];
        long long cost2 = static_cast<long long>(k) * B[i] + C[i];
        ans += min(cost1, cost2);
    }
    
    cout << ans << '\n';
    
    return 0;
}
