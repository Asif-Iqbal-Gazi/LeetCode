/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

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
    ListNode *reverseList(ListNode *head)
    {
        /* Approach:
            1. Using Recursion -- T.C: O(N), S.C: O(N)
            2. Iterative Method -- T.C: O(N), S.C: O(1)
        */

        /* Approach 1
        if (!head || !head->next)
            return head;

        ListNode *res = reverseList(head->next); // For non-null input head, res will be the last node
        head->next->next = head;
        head->next = NULL;
        return res;
        */

        // Approach 2
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;

        while (curr)
        {
            // Get next pointer
            next = curr->next;
            // Make curr point to previous
            curr->next = prev;
            // Make prev our curr
            prev = curr;
            // Make curr our next
            curr = next;
        }
        return prev;
    }
};
// @lc code=end
