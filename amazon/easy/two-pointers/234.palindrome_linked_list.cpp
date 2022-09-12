/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode *head)
    {
        /* Approach:
            1. Two Pointers -- T.C: O(N), S.C: O(1)
            2. Reversing first half Using Fast & Slow Pointer -- T.C: O(N), S.C: O(1)
        */

        // Approach 2
        if (!head->next)
            return true;
        ListNode *dummy = new ListNode(0, head);
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        ListNode *pre = nullptr;
        ListNode *nex = nullptr;

        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            nex = slow->next;
            slow->next = pre;
            pre = slow;
            slow = nex;
        }
        // Check even or odd list
        if (!fast->next)
            nex = slow->next; // Even List
        else
            nex = slow->next->next; // Odd List

        if (slow->val != nex->val)
            return false;
        nex = nex->next;

        while (pre && nex)
        {
            if (pre->val != nex->val)
                return false;
            pre = pre->next;
            nex = nex->next;
        }
        return true;

        /* Approach 1
        int len = 0;
        // Figureout the length
        ListNode *curr = head;
        while (curr)
        {
            curr = curr->next;
            len++;
        }
        if (len == 1)
            return true;
        // Create same length array
        vector<int> lArray(len, -1);
        curr = head;
        int i = 0;
        while (curr)
        {
            lArray[i] = curr->val;
            i++;
            curr = curr->next;
        }
        // Check using two pointers
        int l = 0, r = len - 1;
        while (l < r)
        {
            if (lArray[l++] != lArray[r--])
                return false;
        }
        return true;
        */
    }
};
// @lc code=end
