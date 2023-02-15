// 合并两个有序链表

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), mext(NULL) {}
}

// 循环解法
ListNode* mergeListsLoop(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    ListNode* resultNode = new ListNode();
    ListNode* p = resultNode;

    while (l1 != NULL || l2 != NULL) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        }
        else {
            p->next = l2;
            l2 = l2->next;
        }
    }

    if (l1 != NULL)
        p->next = l1;
    if (l2 != NULL)
        p->next = l2;

    return resultNode->next;
}

// 递归解法
ListNode* mergeListsRecursion(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    if (l1->next < l2->next) {
        l1->next = mergeListsRecursion(l1->next, l2);
        return l1;
    }
    l2->next = mergeListsRecursion(l1, l2->next);
    return l2;
}