#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> P(M);
    for(int i=0; i<M; i++) cin >> P[i];
    
    vector<long long> A(N-1), B(N-1), C(N-1);
    for(int i=0; i<N-1; i++) cin >> A[i] >> B[i] >> C[i];
    
    vector<long long> count(N-1, 0);
    
    for(int i=0; i<M-1; i++){
        int u = P[i] - 1;
        int v = P[i+1] - 1;
        if(u > v) swap(u, v);
        for(int j=u; j<v; j++){
            count[j]++;
        }
    }
    
    long long total = 0;
    for(int i=0; i<N-1; i++){
        long long cost1 = count[i] * A[i];
        long long cost2 = C[i] + count[i] * B[i];
        total += min(cost1, cost2);
    }
    
    cout << total;
}
