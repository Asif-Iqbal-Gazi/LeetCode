/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
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
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        /* Approach:
            Take a next pointer on given node's next node.
            Copy the value of that node to given node.
            Shift both the node and repeat above state, as long as nextPointer->next is not null
        */
        ListNode *prev = nullptr;
        ListNode *currNext = node->next;
        node->val = currNext->val;

        while (currNext)
        {
            node->val = currNext->val;
            currNext = currNext->next;
            prev = node;
            node = node->next;
        }
        prev->next = currNext;
        delete node;
    }
};
// @lc code=end
