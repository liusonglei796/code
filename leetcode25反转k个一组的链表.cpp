class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr){return nullptr;}
        ListNode*dummy=new ListNode(-1);
        dummy->next=head;
        ListNode*p=dummy;

        ListNode*cur=head;
        int len=0;
        while(cur){
            len++;
            cur=cur->next;
        }
        cur=head;
        int b=(len/k); // 这里计算组数，使用整数除法
        while((b!=0)){
            ListNode*temp1=cur;
            ListNode*pre=nullptr;
            int i = k; // 初始化i为k
            while(i!=0){
                ListNode*temp=cur->next;
                cur->next=pre;
                pre=cur;
                cur=temp;
                i--; // i减1
            }
            p->next = pre; // 将反转后的组连接到前一部分链表
            p = temp1; // 更新p指针
            p->next = cur;
            b--; // 组数减1
        }
        ListNode* result = dummy->next;
        delete dummy; // 释放dummy节点内存
        return result;
    }
};