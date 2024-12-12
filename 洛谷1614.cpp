#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    map<int, int> mp;
    mp[0];
    mp[1];
    mp[2];
    mp[3];
    mp[4];
    mp[5];
    mp[6];
    mp[7];
    mp[8];
    mp[9];
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
for(auto it:mp){
    cout<<it.second<<" ";
}
    return 0;
}