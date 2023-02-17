// 相交链表
// 获取两个链表相交的节点

// 解法一
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

// 解法二
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (headA == NULL || headB == NULL)
        return NULL;

    int lenA = 0, lenB = 0;
    ListNode* pA = headA;
    ListNode* pB = headB;
    
    while (pA) {
        lenA++;
        pA = pA->next;
    }
    while (pB) {
        lenB++;
        pB = pB->next;
    }

    if (lenA > lenB) {
        for (int i = 0; i < lenA-lenB; i++) {
            pA = pA->next;
        }
    }
    else {
        for (int i = 0; i < lenB-lenA; i++) {
            pB = pB->next;
        }
    }

    while (pA != NULL && pB != NULL) {
        if (pA == pB)
            return pA;
        pA = pA->next;
        pB = pB->next;
    }

    return NULL;
}