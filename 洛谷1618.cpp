#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	//打表：存储顺序
vector<int>v={1,2,3,4,5,6,7,8,9};
int a,b,c;
cin>>a>>b>>c;
int flag=0;
do{
int a1=v[0]*100+v[1]*10+v[2];
int b1=v[3]*100+v[4]*10+v[5];
int c1=v[6]*100+v[7]*10+v[8];
if(a1*b==b1&&a1*c==c1||(a1==a&&b1==b&&c1==c))
{
    flag=1;
cout<<a1<<" "<<b1<<" "<<c1<<endl;
}
}while(next_permutation(v.begin(),v.end()));
if(!flag){cout<<"No!!!";}


}