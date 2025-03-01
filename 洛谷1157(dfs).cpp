#include<bits/stdc++.h>
using namespace std;

int n, r;
vector<int> b;
vector<bool> used;

void dfs(int pos, int num, int last = 0) {
    if (num == r) {
        for (int i = 0; i < r; i++) {
            cout << setw(3) << b[i];
        }
        cout << endl;
        return;
    }
    for (int i = last + 1; i <= n; ++i) {
       
        
            b[pos] = i;
            dfs(pos + 1, num + 1, i);
      

    }
}

int main() {
    cin >> n >> r;
    b.resize(r);
    used.resize(n + 1);
    dfs(0, 0);
    return 0;
}
