/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        /* Approach:
            1. Linear Scan -- T.C: O(n), S.C: O(1)
        */

        // Edge Case
        if (!head)
            return head;

        ListNode *first = head, *second = head->next;

        while (second)
        {
            if (first->val == second->val)
            {
                first->next = second->next;
                delete second;
                second = first->next;
            }
            else
            {
                first = second;
                second = second->next;
            }
        }

        return head;
    }
};
// @lc code=end
