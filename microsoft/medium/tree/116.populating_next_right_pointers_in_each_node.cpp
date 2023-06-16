/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        /* Approach:
            1. BFS -- T.C: O(V + E), S.C: O(V)
            2. Iterative Optimal Solution -- T.C: O(V), S.C: O(1)
        */

        // Approach 2
        if (!root)
            return root;

        Node *prev = root, *curr;
        while (prev)
        {
            curr = prev;
            while (curr && curr->left)
            {
                // Straight forward left and right children connection
                curr->left->next = curr->right;
                if (curr->next)
                    curr->right->next = curr->next->left;
                curr = curr->next;
            }
            prev = prev->left;
        }
        return root;

        /* Approach 1
        if (!root)
            return root;

        queue<Node *> treeQ;
        treeQ.push(root);

        while (!treeQ.empty())
        {
            int size = treeQ.size();
            Node *prev = nullptr;
            for (int i = 0; i < size; i++)
            {
                if (!prev)
                    prev = treeQ.front();
                else
                {
                    prev->next = treeQ.front();
                    prev = treeQ.front();
                }
                if (prev->left)
                    treeQ.push(prev->left);
                if (prev->right)
                    treeQ.push(prev->right);
                treeQ.pop();
            }
            if (prev)
                prev->next = nullptr;
        }

        return root;
        */
    }
};
// @lc code=end
