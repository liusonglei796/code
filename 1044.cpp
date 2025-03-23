#include <iostream>
#include <vector>

long long catalanDP(int n) {
    std::vector<long long> catalan(n + 1, 0); // Initialize all elements to 0
    catalan[0] = 1; // Base case: C(0) = 1
    catalan[1] = 1; // Base case: C(1) = 1

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i - 1 - j]; // Corrected index
        }
    }
    return catalan[n];
}

int main() {
    int n;
    std::cin >> n;
    std::cout << catalanDP(n);
    return 0;
}