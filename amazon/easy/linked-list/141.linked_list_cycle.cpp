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
        Approach:
            1. Naive Method -- T.C: O(N), S.C: O(1)
            2. Floyd Cycle Detection
        */

        /* Approach 1
        ListNode *curr = head;
        unordered_set<ListNode *> s;

        while (curr)
        {
            if (s.find(curr) != s.end())
                return true;
            s.insert(curr);
            curr = curr->next;
        }
        return false;
        */

        // Approach 2
        if (head == NULL)
            return false;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
// @lc code=end
