/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    ListNode *middleNode(ListNode *head)
    {
        /* Approach:
            1. Naive Method -- T.C: O(N) 2 pass, S.C: O(1)
            2. Slow & Fast Pointer -- T.C: O(N), S.C: O(1)
        */

        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

        /* Approach 1
        int len = 0;
        ListNode *curr = head;
        while (curr)
        {
            len++;
            curr = curr->next;
        }
        int m = len / 2;
        curr = head;
        while (m > 0)
        {
            curr = curr->next;
            m--;
        }
        return curr;
        */
    }
};
// @lc code=end
