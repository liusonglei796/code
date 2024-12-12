class Solution {
public:
  struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    TrieNode() : isEnd(false) {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

// 向字典树中插入字符串
void insert(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        int index = c - 'a';
        if (node->children[index] == nullptr) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isEnd = true;
}

// 计算节点的子节点数量
int countChildren(TrieNode* node) {
    int count = 0;
    for (int i = 0; i < 26; ++i) {
        if (node->children[i]!= nullptr) {
            count++;
        }
    }
    return count;
}

// 查找最长公共前缀
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    TrieNode* root = new TrieNode();
    // 构建字典树
    for (const string& word : strs) {
        insert(root, word);
    }
    TrieNode* cur = root;
    string prefix = "";
    while (cur!= nullptr && cur->isEnd == false && countChildren(cur) == 1) {
        int i;
        for (i = 0; i < 26; ++i) {
            if (cur->children[i]!= nullptr) {
                char c = 'a' + i;
                prefix += c;
                cur = cur->children[i];
                break;
            }
        }
    }
    return prefix;
}
};