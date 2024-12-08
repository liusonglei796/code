#include <iostream>
#include <vector>

class Solution {
public:
    // 构建next数组（前缀数组）
    std::vector<int> buildNext(const std::vector<int>& pattern) {
        int m = pattern.size();
        std::vector<int> next(m, 0);
        int j = 0;
        for (int i = 1; i < m; ++i) {
            while (j > 0 && pattern[i]!= pattern[j]) {
                j = next[j - 1];
            }
            if (pattern[i] == pattern[j]) {
                j++;
            }
            next[i] = j;
        }
        return next;
    }

    // KMP搜索函数，从指定位置开始搜索
    int kmpSearch(const std::vector<int>& text, const std::vector<int>& pattern, int startIndex) {
        int m = pattern.size();
        int n = text.size();
        std::vector<int> next = buildNext(pattern);
        int j = 0;
        for (int i = startIndex; i < n; ++i) {
            while (j > 0 && pattern[j]!= text[i]) {
                j = next[j - 1];
            }
            if (pattern[j] == text[i]) {
                j++;
            }
            if (j == m) {
                return i +1;  // 返回匹配的起始位置（索引从0开始）
            }
        }
        return -1;
    }

    bool canChoose(const std::vector<std::vector<int>>& groups, const std::vector<int>& nums) {
        int numGroups = groups.size();
        if (numGroups == 0) {
            return true;  // 如果没有子数组组，视为满足条件
        }
        if (nums.empty()) {
            return false;  // 如果nums为空，肯定无法满足选择条件
        }
        int startIndex = 0;  // 记录在nums中开始搜索的位置
        for (int i = 0; i < numGroups; ++i) {
            int index = kmpSearch(nums, groups[i], startIndex);
            if (index == -1) {
                return false;
            }
         // 更新下次搜索的起始位置
            if (i < numGroups - 1) {
                int nextIndex = kmpSearch(nums, groups[i + 1], index);
                if (nextIndex == -1 || nextIndex < index) {
                    return false;
                }
            }
        }
        return true;
    }
};