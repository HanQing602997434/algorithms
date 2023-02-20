// 反转链表

ListNode* reverseList(ListNode* head) {
    if (head == NULL)
        return NULL;

    ListNode* preNode = NULL;
    ListNode* curNode = head;
    ListNode* next = NULL;
    while (curNode) {
        next = curNode->next;
        curNode->next = preNode;
        preNode = curNode;
        curNode = next;
    }

    return preNode;
}