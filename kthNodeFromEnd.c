// 链表中倒数第K个节点

ListNode* kthNodeFromEnd(ListNode* head, int kth) {
    if (kth <= 0 || head == NULL) return NULL;
    
    ListNode* fast = head;
    ListNode* slow = head;
    for (int i = 0; i < kth-1; i++) {
        if (fast != NULL) {
            fast = fast->next;
        }       
    }

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}