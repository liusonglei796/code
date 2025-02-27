#include <bits/stdc++.h>
using namespace std;

bool in_memory[1005];  // 记录单词是否在内存中
deque<int> memory;     // 模拟内存队列
int dict_lookups = 0;  // 查词典次数
int mem_size, n;       // 内存大小和单词数量

int main() {
    cin >> mem_size >> n;
    
    for (int i = 0; i < n; ++i) {
        int word;
        cin >> word;
        
        if (!in_memory[word]) {
            dict_lookups++;  // 需要查词典
            
            if (memory.size() >= mem_size) {
                // 内存满了,移除最早的单词
                in_memory[memory.front()] = false;
                memory.pop_front();
            }
            
            // 添加新单词到内存
            memory.push_back(word);
            in_memory[word] = true;
        }
    }
    
    cout << dict_lookups << endl;
    return 0;
}