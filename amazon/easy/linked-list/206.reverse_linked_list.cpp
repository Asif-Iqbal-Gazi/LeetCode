/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        /*
        Approach : Two Pointer
        1. Have a prev & next pointer initially at NULL.
        2. Starting from first node first set next = curr->next, then set curr->next = prev;
        3. Then set prev = curr and curr = next
        4. Loop breaks when curr = NULL, return prev
        */

        // Corner cases
        if (head == NULL or head->next == NULL)
            return head;

        ListNode *prev = NULL;
        ListNode *next = NULL;
        ListNode *curr = head;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
// @lc code=end
