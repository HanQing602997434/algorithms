// 相交链表
// 获取两个链表相交的节点

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (headA == NULL || headB == NULL)
        return NULL;
    ListNode* pA = headA;
    ListNode* pB = headB;
    while (pA != pB) {
        pA = pA == NULL ? headB : pA->next;
        pB = pB == NULL ? headA : pB->next;
    }
    return pA;
}