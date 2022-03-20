/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        /*
        Approach 1:
        1. Get the length of both nodes (n1, n2) and figure out which one is longer
        2. Calculate abs(n1-n2), traverse the longer list for abs(n1-n2)
        3. Then traverse both the list and check if they are equal then return that node

        Approach 2:
        1. Use a while loop with condition nodeA != nodeB
        2. Inside the loop proceed to the next node for both the list.
        3. However, if one of them reaches set it to other list.
        4. Why it works??
        Ans:
            Case 1: If they are of equal lenth and no iteraction. They will simultaneously reach NULL on first pass.
            Case 2: Equal length and itersection. Here, since we are traversing one node at a time, the loop terminates at intersection.
            Case 3: Un-equal length and no itersection. Here, they will reach NULL together on second pass, effective traversal n1 + n2 for both.
            Case 4: Un-equal length and intersection. On Second pass they have same distance from intersection point.
        */

        /* Approach 1
         int n1 = 0;
         int n2 = 0;
         ListNode *temp;
         // Calculate length of first list
         temp = headA;
         while (temp)
         {
             temp = temp->next;
             n1++;
         }
         // Calculate length of second list
         temp = headB;
         while (temp)
         {
             temp = temp->next;
             n2++;
         }
         // Traverse the longest list till abs(n1-n2)
         ListNode *first, *second;
         if (n1 > n2)
         {
             first = headA;
             second = headB;
         }
         else
         {
             first = headB;
             second = headA;
         }
         for (int i = 0; i < abs(n1 - n2); i++)
         {
             first = first->next;
         }
         while (first)
         {
             if (first == second)
                 return first;
             first = first->next;
             second = second->next;
         }
         return NULL;
         */
        // Approach 2
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
        ListNode *a = headA;
        ListNode *b = headB;
        while (a != b)
        {
            a = a == NULL ? headB : a->next;
            b = b == NULL ? headA : b->next;
        }
        return a;
    }
};
// @lc code=end
