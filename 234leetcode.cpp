class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast->next&&fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode*p=slow->next;
        slow->next=nullptr;
        ListNode*pre=nullptr;
        while(p){
ListNode*temp=p->next;
p->next=pre;
pre=p;
p=temp;
        }
while (pre) {
    if (pre->val!= head->val) {
        return false;
    } else {
        pre = pre->next;
        head = head->next;
    }
}
return true;
    }
};