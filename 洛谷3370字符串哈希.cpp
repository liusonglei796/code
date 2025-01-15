#include <iostream>
#include <string>
#include <set>


// 定义哈希函数的参数
const unsigned long long base = 131;
const unsigned long long mod = 1e9 + 9;


// 计算字符串的哈希值
unsigned long long hashValue(const std::string& s) {
    unsigned long long hash = 0;
    unsigned long long power = 1;
    for (char c : s) {
        hash = (hash + (c - 'A' + 1) * power) % mod;
        power = (power * base) % mod;
    }
    return hash;
}


int main() {
    int n;
    std::cin >> n;
    std::set<unsigned long long> uniqueHashes;
    for (int i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        unsigned long long hash = hashValue(str);
        uniqueHashes.insert(hash);
    }
    std::cout << uniqueHashes.size() << std::endl;
    return 0;
}