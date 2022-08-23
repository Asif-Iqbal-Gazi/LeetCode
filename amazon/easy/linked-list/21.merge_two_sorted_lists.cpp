/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        /* Approach:
            1. Using Recursion -- T.C: O(M+N), S.C: O(max(M,N))
            2. Iterative -- T.C: O(M+N)
        */

        /* Approach 1
        // Base Case
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        if (list1->val > list2->val)
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        else
        {
            list1->next = mergeTwoLists(list2, list1->next);
            return list1;
        }
        */

        // Approach 1 -- Tricky Implementation
        // Edge Case
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        if (list1->val > list2->val)
            swap(list1, list2);

        ListNode *res = list1;

        while (list1 && list2)
        {
            ListNode *temp = NULL;
            while (list1 && list1->val <= list2->val)
            {
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            swap(list1, list2);
        }
        return res;
    }
};
// @lc code=end
