#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end()); // 将数组存入哈希集合
        int maxLength = 0;

        for (int num : numSet) {
            // 如果当前数字的前一个数字不在集合中，则从当前数字开始查找连续序列
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentLength = 1;

                // 向后查找连续序列
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentLength++;
                }

                // 更新最大值
                maxLength = max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
};