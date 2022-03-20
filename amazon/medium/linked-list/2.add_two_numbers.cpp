/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode *addTwoNumbers(ListNode *n1, ListNode *n2)
    {
        /*
        Approach:
        1. Iterate through both the list in a while till one of them hits NULL.
        2. During traversal have a sum variable to store the summation of both node + carry(initially zero).
        3. Then store the sum%10 back to both the nodes and set carry = sum/10;
        4. At the end do the same for n1 & n2 with carry if there is any nodes left.
        */

        /*
        int sum = 0;
        int carry = 0;
        bool first = false;
        ListNode *l1 = n1;
        ListNode *l2 = n2;
        ListNode *lastNode = nullptr;
        // Traverse both together
        while (l1 && l2)
        {
            sum = l1->val + l2->val + carry;
            l1->val = sum % 10;
            l2->val = l1->val;
            carry = sum / 10;
            if (!l1->next && !l2->next)
                lastNode = l2;
            l1 = l1->next;
            l2 = l2->next;
        }
        // If l1 has remaining nodes.
        while (l1)
        {
            first = true;
            sum = l1->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;

            if (l1->next == NULL && carry)
            {
                ListNode *carryNode = new ListNode(1);
                l1->next = carryNode;
                carry = 0;
                break;
            }

            l1 = l1->next;
        }
        // If l1 has remaining nodes.
        while (l2)
        {
            sum = l2->val + carry;
            l2->val = sum % 10;
            carry = sum / 10;

            if (l2->next == NULL && carry)
            {
                ListNode *carryNode = new ListNode(1);
                l2->next = carryNode;
                carry = 0;
                break;
            }

            l2 = l2->next;
        }
        if (carry)
        {
            ListNode *carryNode = new ListNode(1);
            lastNode->next = carryNode;
        }
        return first ? n1 : n2;
        */

        // Above code a little tidy up
        int sum = 0;
        int carry = 0;
        bool first = false;
        ListNode *l1 = n1;
        ListNode *l2 = n2;
        ListNode *last = nullptr;

        // Traverse both together
        while (l1 || l2)
        {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;

            if (l1)
            {
                first = true;
                last = l1;
                l1->val = sum % 10;
                l1 = l1->next;
            }
            if (l2)
            {
                first = false;
                last = l2;
                l2->val = sum % 10;
                l2 = l2->next;
            }
        }

        if (carry)
        {
            last->next = new ListNode(carry);
        }
        return first ? n1 : n2;
    }
};
// @lc code=end
