#include <iostream>

int main() {
    int on[25], off[25], num[25];  
    int n, a, m, x;  

    std::cin >> a >> n >> m >> x;


    on[1] = num[1] = a;
    for (int i = 0; i <=2e4 ; i++) {  
        on[2] = off[2] = i;
        num[2] = a;
        for (int j = 3; j <= n - 1; j++) {
            on[j] = on[j - 1] + on[j - 2];
            off[j] = on[j - 1];
            num[j] = num[j - 1] + on[j] - off[j];
        }
        if (num[n - 1] == m) {
            std::cout << num[x] << std::endl;
            break;
        }
    }
  

    return 0;
}