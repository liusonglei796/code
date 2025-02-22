#include<bits/stdc++.h>      // 包含C++标准库的所有头文件
using namespace std;         // 使用标准命名空间
int a,b,c;                  // 声明三个整数变量，用于存储输入的比例关系
vector<int>v1;              // 存储9位数字的向量
vector<array<int,3>>v2;     // 存储满足条件的三个数的结果集
vector<bool>visited;        // 标记数字1-9是否被使用过的布尔数组

void dfs(int pos){          // 深度优先搜索函数，pos表示当前填充的位置
    if(pos==9){            // 如果已经填满9个位置
        // 计算三个三位数
        int n1=v1[0]*100+v1[1]*10+v1[2];    // 第一个三位数
        int n2=v1[3]*100+v1[4]*10+v1[5];    // 第二个三位数
        int n3=v1[6]*100+v1[7]*10+v1[8];    // 第三个三位数
        if(n1*b==n2*a && n1*c==n3*a){       // 检查是否满足比例关系
            v2.push_back({n1,n2,n3});        // 满足条件则保存结果
        }
        return;                              // 返回上一层递归
    }
    
    // 尝试在pos位置填入1-9的数字
    for(int i=1;i<=9;++i){                  // 遍历1到9
        if(!visited[i]){                     // 如果数字i还没被使用过
            visited[i]=true;                 // 标记数字i为已使用
            v1[pos]=i;                       // 在pos位置填入数字i
            dfs(pos+1);                      // 递归填充下一个位置
            visited[i]=false;                // 回溯：恢复数字i为未使用状态
        }
    }
}

int main() {
    cin>>a>>b>>c;           // 输入三个数的比例关系
    v1.resize(9);           // 初始化v1大小为9
    visited.resize(10);     // 初始化visited大小为10（下标0不用，1-9表示数字）
    dfs(0);                 // 从位置0开始搜索
    
    // 输出所有满足条件的结果
    for(const auto& nums : v2){             // 遍历结果集
        cout << nums[0] << " " << nums[1] << " " << nums[2] << "\n";  // 输出每组解
    }
    return 0;
}