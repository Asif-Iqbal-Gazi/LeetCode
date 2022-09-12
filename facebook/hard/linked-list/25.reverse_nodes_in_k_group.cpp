/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        /* Approach:
            Reverse K nodes at a time -- T.C: O(N), S.C: O(1)
        */

        // Edge Case
        if (!head || k == 1)
            return head;

        int len = 0;
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        ListNode *curr = dummy;
        ListNode *next = dummy;
        // Count the length
        while (curr->next)
        {
            curr = curr->next;
            len++;
        }

        while (len >= k)
        {
            curr = prev->next;
            next = curr->next;
            // Each iteration will reverse two node and proceed to next
            for (int i = 1; i < k; i++)
            {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            // Reversing K node done, move to next K nodes
            prev = curr;
            len -= k;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
// @lc code=end
