#include<bits/stdc++.h>
using namespace  std;
struct solution{
int weight;
int value;
int id;
double unit;
};
vector<solution>v(105);
int n,t;
int main(){
cin>>n>>t;
for(int i=1;i<=n;++i){
cin>>v[i].weight>>v[i].value;
v[i].id=i;
v[i].unit=(double)v[i].value/v[i].weight;
}
//左闭右开
sort(v.begin()+1,v.begin()+n+1,[](solution a,solution b){return a.unit>b.unit;});
double sum=0;
for(int i=1;i<=n;++i){
if(t>0){
if(v[i].weight<=t){
sum=sum+v[i].value;
t-=v[i].weight;
}
else{
sum=sum+v[i].unit*t;
t=0;
}}
}
cout<<fixed<<setprecision(2)<<sum;
    return 0;
}
