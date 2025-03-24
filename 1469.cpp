#include <stdio.h>

int main() {
    int n, length, result = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &length);
        result ^= length;
    }
    printf("%d\n", result);
    return 0;
}