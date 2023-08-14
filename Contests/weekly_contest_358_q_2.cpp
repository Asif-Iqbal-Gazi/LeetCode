/*
    2816. Double a Number Represented as a Linked List
    https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/
*/

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
   private:
    // This method will reverse the linked list and return the head of the reversed list
    ListNode *reverseList(ListNode *head) {  // T.C: O(N), S.C: O(1)
        ListNode *curr = head;
        ListNode *prev = nullptr, *next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

   public:
    ListNode *doubleIt(ListNode *head) {
        /* Approach:
            1. Reverse the list and double the values -- T.C: O(N), S.C: O(1)
            2. Single pass to double the values (without reversing) -- T.C: O(N), S.C: O(1)
                -- Credit @lee215
        */

        // Approach 2 -- Single pass to double the values (without reversing) -- T.C: O(N), S.C: O(1)
        // We know that as per description there is always one node in the list
        if (head->val > 4) {
            head = new ListNode(0, head);
        }

        ListNode *curr = head;
        while (curr) {
            curr->val = (curr->val * 2) % 10;
            if (curr->next && curr->next->val > 4)
                curr->val++;
            curr = curr->next;
        }
        return head;

        /* Approach 1 -- Reverse the list and double the values -- T.C: O(N), S.C: O(1)
        ListNode *revHead = reverseList(head);

        int carry = 0;
        ListNode *curr = revHead, *last = nullptr;

        while (curr) {
            int currVal = curr->val * 2 + carry;
            curr->val = currVal % 10;
            carry = currVal / 10;
            last = curr;
            curr = curr->next;
        }

        if (carry) {
            last->next = new ListNode(carry);
        }

        return reverseList(revHead);
        */
    }
};