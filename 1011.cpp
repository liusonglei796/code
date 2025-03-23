#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    
    vector<int> u(n+1), d(n+1), s(n+1);
    u[1] = a;
    s[1] = a;
    d[1] = 0;
    
    // Try values for u[2] = b
    for(int b = 0; b <= 20000; b++) {  // Upper limit based on m <= 2e4
        u[2] = b;
        s[2] = a;  // Key constraint from problem
        d[2] = b - a;
        for(int i = 3; i < n; i++) {
            u[i] = u[i-1] + u[i-2];
            d[i] = u[i-1];
            s[i] = s[i-1] + u[i] - d[i];
        }
        if(s[n-1] == m) {
            cout << s[x] << endl;
            return 0;
        }
    }
    // Problem guarantees a solution exists, so no "no solution" case needed
    return 0;
}