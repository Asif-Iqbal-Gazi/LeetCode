/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        /*
         * Approach:
         * 1. Recursive DFS -- T.C: O(N), S.C: O(N)
         *      - Recursively check if current nodes are equal, then verify
         *        left and right subtrees match.
         * 2. Iterative BFS -- T.C: O(N), S.C: O(N)
         *      - Use a queue to traverse both trees simultaneously,
         *        comparing nodes level by level.
         */

        /* Approach 1 -- Recursive DFS
        // If either of the node is null then, both must be null
        if (!p || !q)
            return p == q;
        return p->val == q->val && isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
        */

        // Approach 2 -- Iterative BFS
        if (!p || !q)
            return p == q;

        queue<TreeNode *> pQueue;
        queue<TreeNode *> qQueue;

        pQueue.push(p);
        qQueue.push(q);

        while (!pQueue.empty()) {
            TreeNode *node1 = pQueue.front();
            TreeNode *node2 = qQueue.front();
            pQueue.pop();
            qQueue.pop();

            if (!node1 && !node2)
                continue;
            if (!node1 || !node2)
                return false;
            if (node1->val != node2->val)
                return false;
            pQueue.push(node1->left);
            qQueue.push(node2->left);
            pQueue.push(node1->right);
            qQueue.push(node2->right);
        }
        return true;
    }
};
