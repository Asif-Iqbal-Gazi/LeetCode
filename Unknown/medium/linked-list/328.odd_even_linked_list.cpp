/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode *oddEvenList(ListNode *head)
    {
        /*
        Approach : Odd_End & Even_End
        1. Have two pointer Odd_End & Even_End.
        2. While traversing identify whether we are on odd or at even index.
        3. If at odd index, link it to Odd_end else link to Even_end.
        4. Finally, make Odd_end->next = Even_end
        */

        // Corner cases
        if (head == NULL || head->next == NULL)
            return head;

        // We will use this varibale to determine our index.
        int count = 0;
        // We need pointer to mark our odd_start & even_start (We will later delete the first dummy entry)
        ListNode *odd_s = new ListNode(1);
        ListNode *even_s = new ListNode(0);
        // Our odd_end and even_end pointer
        ListNode *odd_e = odd_s;
        ListNode *even_e = even_s;

        ListNode *curr = head;
        // This loop will build our odd & even chain
        while (curr)
        {
            count++;
            if (count % 2)
            {
                odd_e->next = curr;
                odd_e = curr;
                curr = curr->next;
                odd_e->next = nullptr;
            }
            else
            {
                even_e->next = curr;
                even_e = curr;
                curr = curr->next;
                even_e->next = nullptr;
            }
        }
        // Our new head will be odd_s->next (first node contains dummy)
        head = odd_s->next;
        // Delete the dummy
        delete odd_s;
        // Odd_end->next will be even_s->next (first node in even chain contains dummy)
        odd_e->next = even_s->next;
        // Delete the dummy
        delete even_s;
        return head;
    }
};
// @lc code=end
