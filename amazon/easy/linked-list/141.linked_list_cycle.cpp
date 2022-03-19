/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    bool hasCycle(ListNode *head)
    {
        /*
        Approach : Floyd Cycle Detection
        1. Use first and slow pointer.
        2. If they meeet there is a loop
        */
        ListNode *slow_p = head;
        ListNode *fast_p = head;
        if (head == NULL)
            return false;
        while (fast_p->next && fast_p->next->next)
        {
            slow_p = slow_p->next;
            fast_p = fast_p->next->next;
            if (slow_p == fast_p)
                return true;
        }
        return false;
    }
};
// @lc code=end
