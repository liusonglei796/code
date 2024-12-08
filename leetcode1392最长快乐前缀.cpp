class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        // 构建next数组
        vector<int> next(n, 0);
        int j = 0;
        for (int i = 1; i < n; ++i) {
            while (j > 0 && s[i]!= s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
        // 根据next数组找到最长快乐前缀
        return s.substr(0,next[n-1]);
    }
};