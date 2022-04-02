/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode *removeElements(ListNode *head, int val)
    {
        /*
        Approach: Using two pointer.
        */

        // This dummy node is necessary for corner case when first node->val = val
        ListNode *dummy = new ListNode(0, head);

        ListNode *prev = dummy;
        ListNode *curr = head;
        while (curr)
        {
            if (curr && curr->val == val)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
// @lc code=end
