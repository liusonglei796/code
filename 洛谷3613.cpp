#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
int n,q;
cin>>n>>q;
unordered_map<int,unordered_map<int,int>>mp;
for(int i=0;i<q;++i){
int a,b,c,d;
cin>>d;
if(d==1){cin>>a>>b>>c;
mp[a][b]=c;
}
if(d == 2){
    cin>>a>>b;
    if(mp[a].find(b)!= mp[a].end()){
        cout<<mp[a][b]<<endl;
    }
}
}
return 0;
}