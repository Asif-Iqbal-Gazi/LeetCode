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
  ListNode *swapPairs(ListNode *head) {
    /* Approach:
     *  1. [Recursion] -- T.C: O(N), S.C: O(N)
     *  2. [Iterative] -- T.C: O(N), S.C: O(1)
     */

    // Iterative
    /* Visualization

        dummy  ┌─prev
       ┌───┐◄──┘    F       S
       │ 0 │────┐
       └───┘    │ ┌───┐   ┌───┐   ┌───┐   ┌───┐
                └►│ 1 │──►│ 2 │──►│ 3 │──►│ 4 │
                  └───┘   └───┘   └───┘   └───┘
    */
    if (head == nullptr || head->next == nullptr)
      return head;

    ListNode *dummy = new ListNode(0, head);
    ListNode *prev  = dummy;

    while (prev->next && prev->next->next) {
      ListNode *first  = prev->next;
      ListNode *second = prev->next->next;

      prev->next   = second;
      first->next  = second->next;
      second->next = first;

      prev = first;
    }

    ListNode *result = dummy->next;
    delete dummy;
    return result;

    /* Recursion
    // Base Case
    if (head == NULL || head->next == NULL)
      return head;

    ListNode *newHead = head->next;
    head->next        = swapPairs(newHead->next);
    newHead->next     = head;
    return newHead;
    */
  }
};
