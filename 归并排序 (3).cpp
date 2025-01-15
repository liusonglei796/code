void merge(vector<int>v,int left,int mid,int right){
vector<int>temp(left+right);
int i=left;
int j=mid+1;
while(i<=mid||j<=right){
int x=i<=mid?v[i]:INT_MAX;
int y=j<=right?v[j]:INT_MAX;
if(x<y){
    temp.push_back(x);
    ++i;
}
else{
    ++j;
    temp.push_back(y);
}
}
for(int i=0;i<temp.size();++i){
    v[left+i]=temp[i];
}
}
void mergeSort(vector<int>v,int left,int right){
if(left>=right)return ;
int mid=(left+right)/2;
mergeSort(v,0,mid);
mergeSort(v,mid+1,v.size()-1);
merge(v,0,mid,v.size()-1);
}