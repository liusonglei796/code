class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head ||!head->next) return head;

        // 分解：找到链表中点
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;

        // 递归地对两个子链表进行排序
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // 合并两个有序链表
        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1? l1 : l2;
        return dummy->next;
    }
};