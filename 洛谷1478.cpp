#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<string>
using namespace std;
bool compare(const pair<int,int>&a,const pair<int,int>&b){
    return a.second<b.second;
}
int main(){
int n,s;
cin>>n>>s;
int a,b;
cin>>a>>b;
vector<pair<int,int>>v;
for(int i=0;i<n;++i){
int c,d;
cin>>c>>d;
if(c<=a+b){v.push_back(make_pair(c,d));}
}
sort(v.begin(),v.end(),compare);
int count=0;
for(int i=0;i<v.size();++i){
s-=v[i].second;
if(s>=0){count++;}
else{break;}
}
cout<<count;

}