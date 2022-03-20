/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        /*
        Approach 1: Naive
        Calculate length, then delete (length - n + 1)th node.

        Approach 2: Two Pointer
        1. Have two pointers "fast" and "slow".
        2. "fast" will traverse n position first.
        3. Then both "fast" and "slow" will traverse one at a time untill "fast" reaches NULL.
        4. When "fast" reaches null, delete the next node of "slow".
        */

        /*Approach 1
        int len = 0;
        ListNode *temp = head;
        while (temp)
        {
            temp = temp->next;
            len++;
        }
        // Corner Case (First element needs to deleted)
        if (len == n)
        {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Travel to the previous node of (len - n + 1)th node
        ListNode *curr = head;
        for (int i = 0; i < (len - n - 1); i++)
        {
            curr = curr->next;
        }
        temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return head;
        */

        /* Approach 2
        ListNode *fast = head;
        ListNode *slow = head;
        // Fast traverses n position first.
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        // Corner case (First element to be deleted)
        if (fast == NULL)
        {
            head = head->next;
            delete slow;
            return head;
        }
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = slow->next->next;
        delete fast;
        return head;
        */

        // Approach 2 with little optimisation that handles the corner case as well.
        // This dummy node is key to corner case
        ListNode *prev = new ListNode(0);
        prev->next = head;

        ListNode *fast = prev;
        ListNode *slow = prev;
        // Fast traverses n position first.
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        // Now we move both fast and slow by one step
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // Delete the next node of slow.
        fast = slow->next;
        slow->next = slow->next->next;
        delete fast;
        head = prev->next;
        delete prev;
        return head;
    }
};
// @lc code=end
