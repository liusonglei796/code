#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	string a,b;
	cin>>a;
	getchar();//其实我不知道要不要吞回车 
	transform(a.begin(),a.end(),a.begin(),::tolower);//使a小写化 
	getline(cin,b);
	b.insert(0," ");//让b前面加个空格 之后用find不怕查不到第一个 
	a=a+' ';
	a.insert(a.begin(),' ');//查找的话以首尾加空格，否则可能查找到其他单词里的字符相同但不是个单独的单词 
	transform(b.begin(),b.end(),b.begin(),::tolower);//小写化 
	if(b.find(a)==-1)
	{
		cout<<"-1";
	}
	else
	{	
		int sum=0;int n=0;
		while(b.find(a,n)!=-1)//find找不到会返回npos也就是-1 
		{	
			sum++;
			n=b.find(a,n)+1;//剩下都好理解 
			
		}
		cout<<sum<<" ";
		cout<<b.find(a);
	}
}