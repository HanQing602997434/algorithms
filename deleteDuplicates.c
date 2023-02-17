// 删除链表中的重复元素

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), mext(NULL) {}
}

// 循环写法
ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL)
        return head;

    ListNode* currentNode = head;
    while (currentNode != NULL) {
        if (currentNode.val == currentNode->next.val) {
            currentNode = currentNode->next->next;
        }
        else {
            currentNode = currentNode->next;
        }
    }

    return head;
}