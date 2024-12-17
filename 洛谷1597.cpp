#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
map <char, int> num;
string st;
int main() {
    cin >> st;
    int len = st.length();
    num['a'] = num['b'] = num['c'] = 0;
    for (int i = 0; i < len; i += 5) {
        if (st[i + 3] >= '0' && st[i + 3] <= '9')
            num[st[i]] = st[i + 3] - '0';
        else
            num[st[i]] = num[st[i + 3]];
    }
    printf("%d %d %d", num['a'], num['b'], num['c']);
    return 0;
}