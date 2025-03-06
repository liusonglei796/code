#include <iostream>
#include <vector>
using namespace std;

const int N = 1e8 + 5;
vector<int> primes;
bool is_composite[N];

void euler_sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (!is_composite[i]) {
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
            is_composite[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    euler_sieve(n);
    
    while (q--) {
        int k;
        cin >> k;
        cout << primes[k-1] << '\n';
    }
    
    return 0;
}