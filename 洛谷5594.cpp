#include <iostream>
#include <set>
using namespace std;

int main() {
	set<int >s[1002];
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int a;
			cin>>a;
			s[a].insert(j+1);
		}
	}
	for(int i=1;i<=k;i++){
		cout<<s[i].size()<<' ' ;
	}
	return 0;
}