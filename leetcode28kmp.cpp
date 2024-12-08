class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        if (n == 0) return 0;  // 空 needle 视为在任何 haystack 中都在开头出现

        vector<int> next = getNext(needle);
        int j = 0;
        for (int i = 0; i < m; ++i) {
            while (j > 0 && haystack[i]!= needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == n) {
                return i - n + 1;  // 返回匹配的起始位置
            }
        }
        return -1;
    }

private:
    vector<int> getNext(const string& needle) {
        int n = needle.size();
        vector<int> next(n, 0);
        int j = 0;
        for (int i = 1; i < n; ++i) {
            while (j > 0 && needle[i]!= needle[j]) {
                j = next[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            next[i] = j;
        }
        return next;
    }
};