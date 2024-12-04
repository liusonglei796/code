class Solution {
public:
ListNode*merge(ListNode*l1,ListNode*l2){
    ListNode*l3=new ListNode(-1);
    ListNode*w=l3;
    while(l1&&l2){
        if(l1->val<l2->val){
            w->next=new ListNode(l1->val);
            l1=l1->next;
        }else{
            w->next=new ListNode(l2->val);
            l2=l2->next;
        }
        w=w->next;
        
    }
    w->next=l1?l1:l2;
    return l3->next;
}
ListNode*middle(ListNode*head){
    ListNode*fast=head;
    ListNode*slow=head;
    while(fast->next&&fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode*mid=slow->next;
    slow->next=nullptr;
    return mid;
}
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
 ListNode*mid=middle(head);
 auto left=sortList(head);
 auto right=sortList(mid);
 return merge(left,right);       
    }
};
