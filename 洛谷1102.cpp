#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, c;
    cin >> n >> c;
    vector<int> nums(n);
    
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    
    long long count = 0;
    for(int i = 0; i < n; i++) {
        count += upper_bound(nums.begin(), nums.end(), nums[i] + c) 
               - lower_bound(nums.begin(), nums.end(), nums[i] + c);
    }
    
    cout << count << "\n";
    return 0;
}