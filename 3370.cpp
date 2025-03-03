#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int MAXN = 10010;
const ull base = 131;

ull getHash(const string& s) {
    ull hash = 0;
    for(char c : s) {
        hash = hash * base + c;
    }
    return hash;
}

int main(){
    int n;
    cin >> n;
    
    vector<ull> hashes;
    string s;
    
    // 计算每个字符串的哈希值
    for(int i = 0; i < n; i++) {
        cin >> s;
        hashes.push_back(getHash(s));
    }
    
    // 排序后去重
    sort(hashes.begin(), hashes.end());
    hashes.erase(unique(hashes.begin(), hashes.end()), hashes.end());
    
    // 输出不同字符串的数量
    cout << hashes.size() << endl;
    
    return 0;
}