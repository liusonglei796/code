#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

// 并查集的查找函数，带路径压缩
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// 并查集的合并函数
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootY] = rootX;
    }
}

// 线性筛法，返回所有>=p的质数
vector<int> linearSieve(int max_num, int p) {
    vector<int> primes;
    vector<bool> is_prime(max_num + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= max_num; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
        for (size_t j = 0; j < primes.size() && i * primes[j] <= max_num; ++j) {
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    // 筛选出>=p的质数
    vector<int> result;
    for (int prime : primes) {
        if (prime >= p) {
            result.push_back(prime);
        }
    }
    return result;
}

int main() {
    int a, b, p;
    cin >> a >> b >> p;

    // 初始化并查集
    parent.resize(b + 1);
    for (int i = a; i <= b; ++i) {
        parent[i] = i;
    }

    // 使用线性筛获取所有>=p的质数
    vector<int> primes = linearSieve(b, p);

    // 对于每个质数，合并其倍数所在的集合
    for (int prime : primes) {
        int first = -1;
        for (int multiple = prime; multiple <= b; multiple += prime) {
            if (multiple >= a) {
                if (first == -1) {
                    first = multiple;
                } else {
                    unite(first, multiple);
                }
            }
        }
    }

    // 统计集合数量
    int count = 0;
    for (int i = a; i <= b; ++i) {
        if (find(i) == i) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}