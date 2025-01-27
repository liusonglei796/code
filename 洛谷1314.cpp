#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

int n, m;
ll s;
vector<ll> w, v;
vector<pair<int, int>> intervals;

ll calculateY(ll W) {
    vector<ll> cnt(n + 1, 0);
    vector<ll> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cnt[i] = cnt[i - 1] + (w[i] >= W ? 1 : 0);
        sum[i] = sum[i - 1] + (w[i] >= W ? v[i] : 0);
    }
    ll y = 0;
    for (const auto& interval : intervals) {
        int l = interval.first, r = interval.second;
        ll current_cnt = cnt[r] - cnt[l - 1];
        ll current_sum = sum[r] - sum[l - 1];
        y += current_cnt * current_sum;
    }
    return y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> s;
    w.resize(n + 1);
    v.resize(n + 1);
    intervals.resize(m);
    
    ll max_w = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
        if (w[i] > max_w) max_w = w[i];
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    
    ll left = 1, right = max_w;
    ll min_diff = LLONG_MAX;
    
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll y = calculateY(mid);
        ll diff = abs(y - s);
        if (diff < min_diff) {
            min_diff = diff;
        }
        if (y > s) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << min_diff << endl;
    return 0;
}