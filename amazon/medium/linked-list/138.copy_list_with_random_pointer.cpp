/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        /* Approach:
            1. Using Unordered_map -- T.C: O(N), S.C: O(N)
            2. Insert + Seperate -- T.C: O(N), S.C: O(1)
                In first pass of iteration insert new nodes.
                In second pass fix the random pointers.
                In Thrid pass segregate the lists
        */

        /* Approach 1
        // Edge Case
        if (!head)
            return nullptr;

        Node *curr = head;
        unordered_map<Node *, Node *> map;

        // Create New Node and build the Map (Pass 1)
        while (curr)
        {
            Node *newNode = new Node(curr->val);
            map[curr] = newNode;
            curr = curr->next;
        }

        curr = head;
        // Pass two fix both the next and random pointer
        while (curr)
        {
            // Fixing 'next' pointer
            map[curr]->next = curr->next == nullptr ? nullptr : map[curr->next];
            // Fixing 'random' pointer
            map[curr]->random = curr->random == nullptr ? nullptr : map[curr->random];
            // Move to next node
            curr = curr->next;
        }

        return map[head];
        */

        // Approach 2
        // Edge Case
        if (!head)
            return nullptr;

        // Insert the new Nodes (1st Pass)
        Node *curr = head;
        while (curr)
        {
            Node *newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = curr->next->next;
        }

        Node *copyHead = head->next;
        // Fix the random pointers of new Nodes (2nd Pass)
        curr = head;
        while (curr)
        {
            curr->next->random = (curr->random == nullptr) ? nullptr : curr->random->next;
            curr = curr->next->next;
        }
        // Seperate the lists (3rd Pass)
        curr = head;
        Node *newCurr = copyHead;
        while (curr && newCurr)
        {
            curr->next = newCurr->next;
            curr = curr->next;
            if (newCurr->next)
                newCurr->next = newCurr->next->next;
            newCurr = newCurr->next;
        }

        return copyHead;
    }
};
// @lc code=end
