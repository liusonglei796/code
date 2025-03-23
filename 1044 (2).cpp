#include <iostream>
#include <vector>

long long catalanDP(int n) {
    std::vector<long long> catalan(n + 1, 0); // Initialize all elements to 0
    //空集的情况： Catalan 数可以用来解决很多计数问题。
	//例如，计算 n 对括号可以有多少种正确的匹配方式。当 n = 0 时，表示没有括号。在这种情况下，只有一种匹配方式，即空集，所以 C₀ = 1。
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