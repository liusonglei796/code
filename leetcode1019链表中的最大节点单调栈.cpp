class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        stack<pair<ListNode*, int>> stk;
        ListNode* cur = head;
        int index = 0;
        while (cur) {
            result.push_back(0);
            while (!stk.empty() && stk.top().first->val < cur->val) {
                result[stk.top().second] = cur->val;
                stk.pop();
            }
            stk.push(make_pair(cur, index));
            cur = cur->next;
            index++;
        }
        return result;
    }
};