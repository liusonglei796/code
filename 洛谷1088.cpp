#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int ord[n];
	for(int i=0;i<n;++i)	cin>>ord[i];
	for(int i=0;i<m;++i)	next_permutation(ord,ord+n);
	for(int i=0;i<n;++i)	cout<<ord[i]<<" ";
	
}
