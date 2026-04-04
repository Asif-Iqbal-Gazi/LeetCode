/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseList(struct ListNode *head) {
    /**
      * Approach:
      * 1. Iterative -- T.C: O(N), S.C: O(1)
      *     - Use three pointers: prev, curr, next. Reverse the link at each node and advance
      forward.
      * 2. Recursive -- T.C: O(N), S.C: O(N)
      *     - Recurse to the end of the list, then reverse links on the way back up the call stack.
      */

    // Approach 1 -- Iterative
    struct ListNode *prevNode = NULL;
    struct ListNode *currNode = head;
    struct ListNode *nextNode = NULL;

    while (currNode) {
        nextNode       = currNode->next;
        currNode->next = prevNode;
        prevNode       = currNode;
        currNode       = nextNode;
    }
    return prevNode;

    /* Approach 2 -- Recursion
    if (!head || !head->next)
        return head;

    struct ListNode *newHead = reverseList(head->next);
    head->next->next         = head;
    head->next               = NULL;
    return newHead;
    */
}
