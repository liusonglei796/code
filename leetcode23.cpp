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
    if (lists.empty()) return nullptr;
    while (lists.size() > 1) {
        std::vector<ListNode*> newlists;
        for (size_t i = 0; i < lists.size(); i += 2) {
            newlists.push_back(mergeTwoLists(lists[i], i + 1 < lists.size() ? lists[i + 1] : nullptr));
        }
        lists = newlists; // Replace the old list with the new merged list
    }
    return lists[0];
}