class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;
        // 创建奇数链表的头节点和尾节点
        ListNode* oddHead = new ListNode(0);
        ListNode* oddTail = oddHead;
        // 创建偶数链表的头节点和尾节点
        ListNode* evenHead = new ListNode(0);
        ListNode* evenTail = evenHead;
        int index = 1;
        while (head) {
            if (index % 2 == 1) {
                oddTail->next = head;
                oddTail = oddTail->next;
            } else {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
            head = head->next;
            index++;
        }
        // 连接奇数链表和偶数链表
        oddTail->next = evenHead->next;
        // 防止出现环
        evenTail->next = nullptr;
        return oddHead->next;
    }
};