/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        /* Approach:
            1. Get Length + Cut + Travese + Join -- T.C: O(N), S.C: O(1)
            2. Above Idea Optimised -- T.C: O(N), S.C: O(1)
        */

        /* Approach 1
        // Edge Case
        if (!head || !head->next)
            return head;

        // Get the length
        int n = 0;
        ListNode *curr = head;
        while (curr)
        {
            curr = curr->next;
            n++;
        }

        // Adjust K
        k = k % n;
        if (k == 0)
            return head;

        // Cutting
        ListNode *fHead = nullptr;
        ListNode *fTail = nullptr;
        ListNode *rHead = head; // Current head will become remaining hed
        curr = rHead;
        // Travese to find final head
        for (int i = 1; i < (n - k); i++)
            curr = curr->next;

        fHead = curr->next;
        curr->next = nullptr;

        curr = fHead;
        // Find the tail of the right cut
        while (curr)
        {
            fTail = curr;
            curr = curr->next;
        }
        // Stiching
        fTail->next = rHead;
        return fHead;
        */

        // Approach 2
        // Edge Case
        if (!head || !head->next || k == 0)
            return head;

        // Calculate the length
        int len = 1;
        ListNode *curr = head;
        while (curr->next && ++len)
            curr = curr->next;

        // Reduce K
        k = k % len;
        // Check if k is zero
        if (k == 0)
            return head;
        k = len - k;

        // Now let make tail point to head (Making the List Circular basically)
        // Also, current is now at last node
        curr->next = head;

        while (k--)
            curr = curr->next;

        // We have reached cutting point
        head = curr->next;
        curr->next = nullptr;
        return head;
    }
};
// @lc code=end
