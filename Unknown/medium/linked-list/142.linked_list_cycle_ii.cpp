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
        Approach : Floyd Cycle Detection Technique
        1. First detect if there is a cycle.
        2. If there is then bring "slow" pointer back to head and traverse keeping count.
        3. Where they meet again return that node.
        */

        /*
         if (head == NULL || head->next == NULL || head->next->next == NULL)
             return NULL;
         ListNode *slow = head;
         ListNode *fast = head;
         // Loop to detect cycle
         while (fast->next && fast->next->next)
         {
             slow = slow->next;
             fast = fast->next->next;
             if (slow == fast)
                 break;
         }
         // Above loop didn't find a cycle ?
         if (fast->next == NULL || fast->next->next == NULL)
             return NULL;
         // There is a cycle
         slow = head;
         while (slow != fast)
         {
             slow = slow->next;
             fast = fast->next;
         }
         return slow;
         */
        // Little optimised code or may be looks neat
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        // Loop to detect cycle
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                // Found a loop let's detect the node
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        // There is no cycle
        return NULL;
    }
};
// @lc code=end
