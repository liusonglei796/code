class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) {
            return head;
        }

        // 创建虚拟头节点
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* q = dummy;
        // 让q指针移动到要反转区间的起始节点的前一个节点
        for (int i = 0; i < left - 1 && q!= nullptr; ++i) {
            q = q->next;
        }
        // 保存要反转区间的起始节点和末尾节点
        ListNode* temp1 = q->next;
        ListNode* pre = nullptr;
        ListNode* cur = temp1;
        // 反转指定区间内的节点
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        // 重新连接链表节点
        q->next = pre;
        temp1->next = cur;

        return dummy->next;
    }
};