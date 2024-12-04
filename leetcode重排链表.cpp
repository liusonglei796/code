class Solution {
public:
    void reorderList(ListNode* head) {
     ListNode*fast=head;
     ListNode*slow=head;
     while(fast->next&&fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
     }   
ListNode*cur=slow->next;
slow->next=nullptr;
ListNode*pre=nullptr;
while(cur){
ListNode*temp=cur->next;
cur->next=pre;
pre=cur;
cur=temp;
}
while(pre){
ListNode*temp1=head->next;
ListNode*temp2=pre->next;
head->next=pre;pre->next=temp1;
head=temp1;
pre=temp2;
}

    }
};