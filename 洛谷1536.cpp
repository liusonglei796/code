#include<iostream>
using namespace std;
int f[1005];

int find(int x){
    if(f[x]==x){return x;}
    return f[x]=find(f[x]);
}

int main(){
    int n,m;
    while(cin>>n&&n!=0){
        cin>>m;
        for(int i=1;i<=n;++i){
            f[i]=i;
        }

        for(int j=0;j<m;++j){
            int a,b;
            cin>>a;
            cin>>b;
            int x1 = find(a);
            int x2 = find(b);
            if(x1!=x2){
                f[x1]=x2;
            }
        }

        int count = 0;
        for(int i=1;i<=n;++i){
            if(f[i]==i){
                count++;
            }
        }
        cout<<count - 1<<endl;
    }
    return 0;
}