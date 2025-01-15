#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    list<int> lt;
    vector<list<int>::iterator> p(n+1);
    vector<bool> removed(n+1, false);
    
    // Insert first element
    p[1] = lt.insert(lt.begin(), 1);
    
    // Process insertions
    for(int i = 2; i <= n; i++) {
        int id, op;
        cin >> id >> op;
        if(op == 0) {
            p[i] = lt.insert(p[id], i);
        } else {
            p[i] = lt.insert(next(p[id]), i);
        }
    }
    
    // Process removals
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int id;
        cin >> id;
        if(!removed[id]) {
            lt.erase(p[id]);
            removed[id] = true;
        }
    }
    
    // Output result
    for(int x : lt) {
        cout << x << " ";
    }
    
    return 0;
}