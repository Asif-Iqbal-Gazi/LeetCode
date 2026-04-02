/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow_ptr = head;
    struct ListNode *fast_ptr = head;

    while (fast_ptr && fast_ptr->next) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr)
            return true;
    }
    return false;
}
