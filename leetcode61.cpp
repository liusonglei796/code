class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr){
            return head;
        }
        ListNode*p=head;
        int len=1;
        while(p->next){
            len++;
            p=p->next;
        }
        p->next=head;
        p=head;
        for(int i=0;i<len-k%len-1;++i){
            p=p->next;
        }
      ListNode*w=p->next;
      p->next=nullptr;

        return w;
    }
};