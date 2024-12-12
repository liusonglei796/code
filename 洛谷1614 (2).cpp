#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    map<int, int> mp;
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        long long temp1 = i;  // 将temp1类型改为long long，避免整数溢出
        while (temp1!= 0) {
            int temp2 = temp1 % 10;
            temp1 /= 10;
            mp[temp2]++;
        }
    }
    // 遍历0到9并输出出现次数
for(int j=0;j<=9;++j){
    if(mp.find(j)!=mp.end()){
        cout<<mp[j]<<" ";
    }else{
        cout<<0<<" ";
    }
}
    return 0;
}