/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 */

// @lc code=start
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
class Solution
{
private:
    bool check(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        return true;
    }

public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        /* Approach:
            1. Recursion
            2. Iterative -- Using Queue
            3. Iterative -- (More readable ??)
        */

        /* Approach 1
        // Base Cases
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;

        return isSameTree(p->right, q->right) &&
               isSameTree(p->left, q->left);
        */

        /* Approach 2
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;

        queue<TreeNode *> pQueue;
        queue<TreeNode *> qQueue;
        pQueue.push(p);
        qQueue.push(q);

        while (!pQueue.empty() && !qQueue.empty())
        {
            TreeNode *node1 = pQueue.front();
            TreeNode *node2 = qQueue.front();
            pQueue.pop();
            qQueue.pop();
            // If either one of them is NULL
            if ((node1 == NULL && node2 != NULL) || (node1 != NULL && node2 == NULL))
                return false;
            // If the nodes are non-null and doesn't contain same value
            if (node1 && node2 && (node1->val != node2->val))
                return false;
            else if (node1 && node2 && (node1->val == node2->val))
            {
                pQueue.push(node1->left);
                pQueue.push(node1->right);
                qQueue.push(node2->left);
                qQueue.push(node2->right);
            }
        }
        return true;
        */

        // Approach 3
        // Edge Cases
        if (!p && !q)
            return true;
        if (!check(p, q))
            return false;

        queue<TreeNode *> pQueue;
        queue<TreeNode *> qQueue;
        pQueue.push(p);
        qQueue.push(q);

        while (!pQueue.empty())
        {
            TreeNode *node1 = pQueue.front();
            TreeNode *node2 = qQueue.front();
            pQueue.pop();
            qQueue.pop();

            if (!check(node1, node2))
                return false;
            // Check if both nodes are non null push their children
            if (node1 && node2)
            {
                pQueue.push(node1->left);
                qQueue.push(node2->left);
                pQueue.push(node1->right);
                qQueue.push(node2->right);
            }
        }
        return true;
    }
};
// @lc code=end
