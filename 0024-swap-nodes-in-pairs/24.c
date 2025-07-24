/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *swapPairs(struct ListNode *head) {
  /* Approach:
     1. [Recursion] -- T.C: O(N), S.C: O(N)
     2. [Iterative] -- T.C: O(N), S.C: O(1)
  */

  // Iterative
  struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
  dummy->val             = 0;
  dummy->next            = head;
  struct ListNode *prev  = dummy;

  while (prev->next && prev->next->next) {
    struct ListNode *first  = prev->next;
    struct ListNode *second = prev->next->next;

    prev->next   = second;
    first->next  = second->next;
    second->next = first;

    prev = first;
  }
  struct ListNode *new_head = dummy->next;
  free(dummy);
  return new_head;

  /* Recursion
  if (head == NULL || head->next == NULL)
    return head;

  struct ListNode *new_head = head->next;
  head->next                = swapPairs(new_head->next);
  new_head->next            = head;
  return new_head;
  */
}
