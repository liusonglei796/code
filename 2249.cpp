#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v(1000005,-1);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    for(int i=0;i<m;++i){
        int x;
        cin>>x;
        auto it=lower_bound(v.begin(),v.begin()+n,x);
        if(it==v.begin()+n||*it!=x){
            cout<<"-1 ";
        }else{
            // Output 1-based index
            cout<<(it-v.begin())+1<<" ";
        }
    }
    return 0;
}