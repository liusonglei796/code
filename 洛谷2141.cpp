#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    // 用set记录所有可能的和
    set<int> sums;
    // 用set记录作为和的数
    set<int> result;
    
    // 找出所有可能的两数之和
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            sums.insert(nums[i] + nums[j]);
        }
    }
    
    // 检查每个数是否为某两数之和
    for(int i = 0; i < n; i++){
        if(sums.find(nums[i]) != sums.end()){
            result.insert(nums[i]);
        }
    }
    
    cout << result.size() << endl;
    
    return 0;
}