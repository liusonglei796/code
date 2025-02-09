
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        // 数字到字母的映射
        unordered_map<char, string> digit_to_letters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> result;
        string current_combination;
        backtrack(digits, 0, digit_to_letters, current_combination, result);
        return result;
    }

private:
    void backtrack(const string& digits, int index, const unordered_map<char, string>& digit_to_letters, string& current_combination, vector<string>& result) {
        // 如果当前组合的长度等于输入数字的长度，说明已经完成一个组合
        if (index == digits.length()) {
            result.push_back(current_combination);
            return;
        }

        // 获取当前数字对应的字母列表
        char current_digit = digits[index];
        const string& letters = digit_to_letters.at(current_digit);

        // 遍历当前数字对应的所有字母
        for (char letter : letters) {
            // 将当前字母加入组合
            current_combination.push_back(letter);
            // 递归处理下一个数字
            backtrack(digits, index + 1, digit_to_letters, current_combination, result);
            // 回溯，移除当前字母
            current_combination.pop_back();
        }
    }
};