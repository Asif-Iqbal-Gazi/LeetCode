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
            2. Iterative Using Dummy Node -- T.C: O(M+N), S.C: O(1)
            3. Iterative Optimal -- T.C: O(M+N)
        */

        /* Approach 1 -- Recursion
        // Base Cases
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list2->next, list1);
            return list2;
        }
        */

        /* Approach 2
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        while (list1 && list2)
        {
            // If first one contains smaller element
            if (list1->val < list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        // If there are remianing elements
        curr->next = (list1 == nullptr) ? list2 : list1;
        curr = dummy->next;
        delete dummy;
        return curr;
        */

        // Approach 3 -- Tricky Implementation
        // Edge Cases
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        if (list1->val > list2->val)
            swap(list1, list2);

        ListNode *res = list1, *temp = nullptr;

        while (list1 && list2)
        {
            temp = nullptr;
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
