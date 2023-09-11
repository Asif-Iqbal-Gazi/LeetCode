/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        /* Approach:
            1. Linear Scan + Mark + Reverse -- T.C: O(N), S.C: O(1)
            2. Linear Scan (One Pass) -- T.C: O(N), S.C: O(1)
        */

        // Approach 2 -- One Pass
        if (left == right) return head;
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy, *curr = dummy;
        ListNode *next, *revHead, *revTail, *tPrev, *tNext;

        tPrev = nullptr;

        int count = 0;
        while (curr) {
            if (count < left) {
                tNext = curr->next;
                tPrev = curr;
                curr = tNext;
            } else if (count == left) {
                prev = tPrev;
                revTail = curr;
                tNext = curr->next;
                curr->next = nullptr;
                tPrev = curr;
                curr = tNext;
            } else if (count == right) {
                tNext = curr->next;
                curr->next = tPrev;
                tPrev = curr;
                curr = tNext;
                next = tNext;
                revHead = tPrev;
                break;
            } else {
                tNext = curr->next;
                curr->next = tPrev;
                tPrev = curr;
                curr = tNext;
            }

            count++;
        }

        prev->next = revHead;
        revTail->next = next;

        curr = dummy->next;
        delete dummy;
        return curr;

        /* Approach 1
        if (left == right) return head;
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy, *curr = dummy;
        ListNode *next, *revHead, *revTail;

        int count = 0;
        // Linear Scan and Mark pointers
        while (curr) {
            count++;
            if (count == left) {
                prev = curr;
                revTail = prev->next;
            }
            curr = curr->next;
            if (count == right) {
                next = curr->next;
                revHead = curr;
                revHead->next = nullptr;
            }
        }

        ListNode *tNext, *tPrev = nullptr;
        curr = revTail;
        // Reverse the [left, right] segment
        while (curr) {
            tNext = curr->next;
            curr->next = tPrev;
            tPrev = curr;
            curr = tNext;
        }

        // Join with main list
        prev->next = revHead;
        revTail->next = next;

        curr = dummy;
        curr = curr->next;
        delete dummy;
        return curr;
        */
    }
};
// @lc code=end
