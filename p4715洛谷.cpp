
#include<iostream>
#include<cstring>
#include<algorithm> //�[��򄡋S� 4��
#include<cmath>
#include<iomanip> 
using namespace std;
struct jiegouti{  //�ӄS
 	int power,id;  //power��<id����
}; 
jiegouti maxt(jiegouti a,jiegouti b){  //��$*ӄS���<�'��*
	return a.power>b.power?a:b;
}
jiegouti mint(jiegouti a,jiegouti b){ //��$*ӄS���<�'��*
	return a.power<b.power?a:b;
}
jiegouti a[150],tree[600];  //apntree�� ,:�2���/ pĄ4z�	
void build(int node,int start,int end){ //��p
	if(start==end){  //�����
		tree[node]=a[start];
		return;
	}
	int lnode=node*2;  //��P-�
	int rnode=node*2+1;
	int mid=(start+end)/2;
	build(lnode,start,mid);  //$�R�
	build(rnode,mid+1,end);
	tree[node]=maxt(tree[lnode],tree[rnode]) ; //6��/��P����'�;
}
int main(){
	int n;  //�e
	cin>>n;
	for(int i=1;i<=(1<<n);i++){  //1<<n1/2�n!�f�7�pow�p���	
		cin>>a[i].power;  //�eK<��U
		a[i].id=i;	
	}
	build(1,1,(1<<n)); //�9��/1t��102�n!�	
	cout<<mint(tree[2],tree[3]).id; //�tree[2],tree[3]�~*�1/��������
	return 0;
}