#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int M, N;  // M是内存容量，N是单词数量
    cin >> M >> N;
    
    vector<int> words(N);  // 存储所有单词
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }
    
    deque<int> memory;  // 模拟内存
    int lookups = 0;    // 查词典次数
    
    // 处理每个单词
    for (int word : words) {
        // 检查单词是否在内存中
        if (find(memory.begin(), memory.end(), word) == memory.end()) {
            // 需要查词典
            lookups++;
            
            // 如果内存满了，移除最早的单词
            if (memory.size() == M) {
                memory.pop_front();
            }
            
            // 将新单词加入内存
            memory.push_back(word);
        }
    }
    
    cout << lookups << endl;
    return 0;
}
