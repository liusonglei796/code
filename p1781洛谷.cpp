#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<utility>
#include<string>
using namespace std;
bool compare(const pair<int,string>&a,const pair<int,string> &b){
    if(a.second.size()<b.second.size()){return false;}
    if(a.second.size()>b.second.size()){return true;}
    if(a.second.size()==b.second.size()){
string c=a.second;
string d=b.second;
for(int i=0;i<c.size();){
if(c[i]-'0'>d[i]-'0'){return true;}
else if(c[i]-'0'<d[i]-'0'){return false;}
else{++i;}
}
}}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
int n;
cin>>n;
vector<pair<int,string>>v;
for(int i=1;i<=n;++i){
string input;
cin>>input;
v.push_back(make_pair(i,input));
}  
sort(v.begin(),v.end(),compare);
cout<<v[0].first<<endl<<v[0].second;
    return 0;
}