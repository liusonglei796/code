class Solution {
public:vector<int> buildPrefix(const vector<int>& pattern) {
    int m = pattern.size();
    vector<int> prefix(m, 0);
    int j = 0;
    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[j] != pattern[i]) {
            j = prefix[j - 1];
        }
        if (pattern[j] == pattern[i]) {
            ++j;
        }
        prefix[i] = j;
    }
    return prefix;
}

// KMP算法查找子数组
bool kmpSearch(const vector<int>& text, const vector<int>& pattern, int& index) {
    int n = text.size(), m = pattern.size();
    vector<int> prefix = buildPrefix(pattern);
    int j = 0;
    for (int i = index; i < n; ++i) {
        while (j > 0 && pattern[j] != text[i]) {
            j = prefix[j - 1];
        }
        if (pattern[j] == text[i]) {
            ++j;
        }
        if (j == m) {
            index = i + 1; // 更新下一次搜索的起始位置
            return true;
        }
    }
    return false;
}
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
            int n = groups.size();
    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (!kmpSearch(nums, groups[i], index)) {
            return false; // 如果找不到匹配的子数组，返回false
        }
        // 检查下一个子数组是否在当前子数组之后
        if (i < n - 1) {
            int nextIndex = index;
            if (kmpSearch(nums, groups[i + 1], nextIndex) && nextIndex <= index) {
                return false; // 如果下一个子数组与当前子数组有重叠，返回false
            }
        }
    }
    return true;
    }
};