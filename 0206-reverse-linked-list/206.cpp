/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        /*
         * Approach:
         * 1. Iterative -- T.C: O(N), S.C: O(1)
         *      - Use three pointers: prev, curr, next.
         *        Reverse the link at each node and advance forward.
         * 2. Recursive -- T.C: O(N), S.C: O(N)
         *      - Recurse to the end of the list, then reverse
         *        links on the way back up the call stack.
         */

        // Approach 1 -- Iterative
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next     = prev;
            prev           = curr;
            curr           = next;
        }
        return prev;

        /* Approach 2 -- Recursive
        if (!head || !head->next)
            return head;
        ListNode *newHead  = reverseList(head->next);
        head->next->next   = head;
        head->next         = nullptr;
        return newHead;
        */
    }
};
