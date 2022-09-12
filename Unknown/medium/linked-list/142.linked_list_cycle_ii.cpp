/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head)
    {
        /*
        Approach :
            1. Naive Method -- T.C: O(N), S.C: O(N)
            2. Floyd Cycle Detection Technique -- T.C: O(N), S.C: O(1)
                First detect if there is a cycle.
                If there is then bring "slow" pointer back to head and traverse keeping count.
                Where they meet again return that node.
        */

        /* Approach 1
        if (!head)
            return nullptr;

        ListNode *curr = head;
        unordered_set<ListNode *> s;

        while (curr)
        {
            if (s.find(curr) != s.end())
                return curr;
            s.insert(curr);
            curr = curr->next;
        }
        return nullptr;
        */

        // Approach 2
        if (!head || !head->next || !head->next->next)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;
        // Loop Detection
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                // Found a loop
                fast = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        // No loop detected
        return nullptr;
    }
};
// @lc code=end
