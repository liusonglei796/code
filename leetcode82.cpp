class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* dummy = new ListNode(0); // 创建一个哑节点作为新链表的头部
        dummy->next = head;
        ListNode* prev = dummy; // prev 用于记录当前节点的前一个节点

        while (head != nullptr) {
            while (head->next != nullptr && head->val == head->next->val) {
                // 如果当前节点和下一个节点值相同，移动 head 指针跳过重复的节点
                head = head->next;
            }
            if (prev->next == head) {
                // 如果没有重复，即当前节点和下一个节点值不同，则移动 prev 指针
                prev = prev->next;
            } else {
                // 如果有重复，即当前节点和下一个节点值不同，更新 prev 的 next 指针跳过重复的节点
                prev->next = head->next;
            }
            head = head->next; // 移动 head 指针到下一个节点
        }
        ListNode* newHead = dummy->next; // 新链表的头节点
        delete dummy; // 删除哑节点
        return newHead; // 返回新链表的头节点
    }
};