class Solution {
public:
    bool hasCycle(ListNode *head) {
  if(head==nullptr){
    return head;
  }
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast&&fast->next){
fast=fast->next->next;
slow=slow->next;
if(fast==slow){
    return true;
}
        }
        return false;
    }
};