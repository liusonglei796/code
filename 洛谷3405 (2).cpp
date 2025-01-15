#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    // city_prefix -> {state -> count}
    unordered_map<string, unordered_map<string, int>> prefix_state;
    long long ans = 0;
    
    for(int i = 0; i < n; i++) {
        string city, state;
        cin >> city >> state;
        string prefix = city.substr(0, 2);
        
        // 检查是否存在特殊对
        if(prefix_state.count(state)) {
            for(const auto& p : prefix_state[state]) {
                // 正确的检查：前缀相等且州不同
                if(p.first == prefix && p.first!= state) {
                    ans += p.second;
                }
            }
        }
        
        // 更新当前城市信息
        prefix_state[prefix][state]++;
    }
    
    cout << ans << endl;
    return 0;
}