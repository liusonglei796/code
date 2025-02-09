#include<bits/stdc++.h>  // 包含C++的标准库
using namespace std;     // 使用标准命名空间

int m,n;  // m所学校，n个学生
int a[100005];  // 学校预计分数线
int b[100005];  // 学生估分

int main() {
    ios::sync_with_stdio(0);  // 优化输入输出
    cin.tie(0);
    
    cin>>m>>n;  // 输入学校数和学生数
    
    // 输入m所学校的预计分数线
    for(int i=0;i<m;++i){
        cin>>a[i];
    }
    // 输入n个学生的估分
    for(int i=0;i<n;++i){
        cin>>b[i];
    }
    
    sort(a,a+m);  // 将学校分数线排序
    long long ans=0;  // 存储总不满意度
    
    // 对每个学生找最合适的学校
    for(int i=0;i<n;++i){
        int target=b[i];  // 当前学生的估分
        int l=0;
        int r=m-1;
        int closest=a[0];  // 存储最接近的分数线
        
        // 二分查找最接近的分数线
        while(l<=r){
            int mid=l+(r-l)/2;
            // 更新最接近的值
            if(abs(a[mid]-target) < abs(closest-target)){
                closest = a[mid];
            }
            if(a[mid]>target){
                r=mid-1;
            }else if(a[mid]<target){
                l=mid+1;
            }else{
                closest = target;  // 找到完全相等的值
                break;
            }
        }
        
        ans += abs(closest-target);  // 加上这个学生的不满意度
    }
    
    cout << ans << endl;  // 输出总不满意度
    return 0;
}