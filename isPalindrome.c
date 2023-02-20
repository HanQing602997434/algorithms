// 回文链表

bool isPalindrome(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // 如果链表节点个数为奇数个，把中间节点归到左边
    if (fast != NULL) {
        slow = slow->next;
    }

    slow = reverse(slow);
    fast = head;

    while (slow != NULL) {
        if (fast->val != slow->val) {
            return false;
        }
        fast = fast->next;
        slow = slow->next;
    }

    return true;
}