/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    bool hasCycle(ListNode *head) {
        /* Approach:
            1. Fast and Slow Pointer -- T.C: O(N), S.C: O(1)
        */

        if (head == nullptr)
            return false;

        ListNode *fast = head, *slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }

        return false;
    }
};
