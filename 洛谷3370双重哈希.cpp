#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int BASE1 = 131;
const int BASE2 = 13331;
const int MOD = 1e9 + 7;

// 计算双哈希值
pair<ull, ull> getHash(const string& s) {
    ull hash1 = 0, hash2 = 0;
    for(char c : s) {
        hash1 = hash1 * BASE1 + c;
        hash2 = hash2 * BASE2 + c;
    }
    return {hash1, hash2};
}

struct PairHash {
    size_t operator()(const pair<ull, ull>& p) const {
        return p.first ^ (p.second << 32);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    unordered_set<pair<ull, ull>, PairHash> hashes;
    
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        hashes.insert(getHash(s));
    }
    
    cout << hashes.size() << endl;
    
    return 0;
}
