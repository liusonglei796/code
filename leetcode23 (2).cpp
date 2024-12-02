ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    return mergeKListsHelper(lists, 0, lists.size() - 1);
}

ListNode* mergeKListsHelper(std::vector<ListNode*>& lists, int start, int end) {
    if (start == end) return lists[start];
    if (start > end) return nullptr;
    
    int mid = start + (end - start) / 2;
    ListNode* l1 = mergeKListsHelper(lists, start, mid);
    ListNode* l2 = mergeKListsHelper(lists, mid + 1, end);
    return mergeTwoLists(l1, l2);
}