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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    /* Approach:
       1. [Recursion] -- T.C: O(M + N), S.C: O(max(M, N))
       2. [Iterative Using Dummy Node] -- T.C: O(M + N), S.C: O(1)
       3. [Iterative, In-Place Swap] -- T.C: O(M + N), S.C: O(1)
    */

    /* Approach 3 -- Tricky Implementation
    // Edge Cases
    if (!list1)
      return list2;
    if (!list2)
      return list1;

    if (list1->val > list2->val)
      swap(list1, list2);

    ListNode *res = list1, *temp = nullptr;

    while (list1 && list2) {
      temp = nullptr;
      while (list1 && list1->val <= list2->val) {
        temp  = list1;
        list1 = list1->next;
      }
      temp->next = list2;
      swap(list1, list2);
    }
    return res;
    */

    // Approach 2: Iterative Using Dummy Node
    if (list1 == nullptr)
      return list2;
    if (list2 == nullptr)
      return list1;

    // ListNode *dummy = new ListNode(0);
    // ListNode *curr  = dummy;
    ListNode  dummy(0);
    ListNode *curr = &dummy;

    while (list1 && list2) {
      if (list1->val < list2->val) {
        curr->next = list1;
        list1      = list1->next;
      } else {
        curr->next = list2;
        list2      = list2->next;
      }
      curr = curr->next;
    }
    curr->next = list1 ? list1 : list2;
    // curr       = dummy->next;
    // delete dummy;
    // return curr;
    return dummy.next;

    /* Approach 1: Recursion
    // Base Cases
    if (list1 == nullptr)
      return list2;
    if (list2 == nullptr)
      return list1;

    if (list1->val <= list2->val) {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    } else {
      list2->next = mergeTwoLists(list2->next, list1);
      return list2;
    }
    */
  }
};
