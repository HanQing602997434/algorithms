// 链表的中间节点

ListNode* middleNode(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}