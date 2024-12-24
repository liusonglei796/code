#include <iostream>
#include <list>
#include <unordered_set>
using namespace std;

int main() {
    list<int> memoryList;  // 用于模拟内存单词存储顺序
    int m, n;
    cin >> m >> n;
    unordered_set<int> memorySet;  // 用于快速判断单词是否已在内存中
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int word;
        cin >> word;
        // 检查单词是否在内存中
        if (memorySet.find(word) == memorySet.end()) {
            count++;
            // 如果内存已满
            if (memorySet.size() == m) {
                int firstWord = memoryList.front();
                memoryList.pop_front();
                memorySet.erase(firstWord);
            }
            memorySet.insert(word);
            memoryList.push_back(word);
        }
    }
    cout << count << endl;
    return 0;
}
