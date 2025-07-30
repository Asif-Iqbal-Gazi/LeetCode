/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
  /* Approach:
     1. [Iterative] -- T.C: O(M + N), S.C: O(1)
  */

  struct ListNode dummy;
  dummy.val             = 0;
  struct ListNode *curr = &dummy;

  while (list1 && list2) {
    if (list1->val <= list2->val) {
      curr->next = list1;
      list1      = list1->next;
    } else {
      curr->next = list2;
      list2      = list2->next;
    }
    curr = curr->next;
  }
  curr->next = list1 ? list1 : list2;
  return dummy.next;
}
