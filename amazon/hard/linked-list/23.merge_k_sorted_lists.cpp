/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (l2->val < l1->val)
            swap(l1, l2);

        ListNode *res = l1;

        while (l1 && l2)
        {
            ListNode *temp = nullptr;
            while (l1 && l1->val <= l2->val)
            {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            swap(l1, l2);
        }
        return res;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        /* Approach:
            1. Naive -- T.C: O(N*k), S.C: O(1)
                Have an inplace merge method and call it for all the lists
        */

        int n = lists.size();
        // Edge case
        if (n == 0)
            return nullptr;

        ListNode *res = nullptr;

        for (ListNode *curr : lists)
            res = mergeTwoLists(curr, res);
        return res;
    }
};
// @lc code=end
