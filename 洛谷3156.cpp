#include <iostream>
#include <string>
#include<unordered_map>
using namespace std;
int main(){
unordered_map<int,int>mp;
int n,m;
cin>>n>>m;
for(int i=1;i<=n;++i){
    int input;
    cin>>input;
    mp[i]=input;
}
for(int i=0;i<m;++i){
    int input;
    cin>>input;
    if(mp.find(input)!=mp.end()){
        cout<<mp[input]<<endl;
    }
}



}