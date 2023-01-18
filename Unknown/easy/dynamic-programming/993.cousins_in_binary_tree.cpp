/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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
    /*
    TreeNode *doBFS(TreeNode *root, int &depth, int target)
    {
        queue<pair<TreeNode *, pair<TreeNode *, int>>> q;
        q.push({root, {nullptr, 0}});

        while (!q.empty())
        {
            int q_sz = q.size();
            for (int i = 0; i < q_sz; i++)
            {
                TreeNode *curr = q.front().first;
                int currDepth = q.front().second.second;
                if (curr->val == target)
                {
                    depth = currDepth;
                    return q.front().second.first;
                }
                q.pop();
                if (curr->left)
                    q.push({curr->left, {curr, currDepth + 1}});
                if (curr->right)
                    q.push({curr->right, {curr, currDepth + 1}});
            }
        }
        return nullptr;
    }
    */
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        /* Approach:
            1. Naive Method -- T.C: O(N), S.C: O(N)
                Find parent and depth of x & y. Then decide
            2. Optimised Naive Method -- T.C: O(N), S.C: O(N)
        */

        // Approach 2
        int xDepth = 0;
        int yDepth = 0;
        // As every node has unique value, we will use the value of parent
        int xParent = 0;
        int yParent = 0;

        queue<pair<TreeNode *, pair<int, int>>> q;
        // Push root with depth 0 and parent as -1 or nullptr
        q.push({root, {-1, 0}});

        // Start BFS
        while (!q.empty())
        {
            int q_sz = q.size();
            for (int i = 0; i < q_sz; i++)
            {
                TreeNode *curr = q.front().first;
                int parent = q.front().second.first;
                int currDepth = q.front().second.second;
                q.pop();
                // Check value of curr
                if (curr->val == x)
                {
                    xDepth = currDepth;
                    xParent = parent;
                }
                else if (curr->val == y)
                {
                    yDepth = currDepth;
                    yParent = parent;
                }
                // Push children in to queue
                if (curr->left)
                    q.push({curr->left, {curr->val, currDepth + 1}});
                if (curr->right)
                    q.push({curr->right, {curr->val, currDepth + 1}});
            }
        }
        return (xDepth == yDepth && xParent != yParent) ? true : false;

        /* Approach 1
        int depthOne = 0;
        int depthTwo = 0;
        TreeNode *parent1 = doBFS(root, depthOne, x);
        TreeNode *parent2 = doBFS(root, depthTwo, y);
        return (parent1 != parent2 && depthOne == depthTwo) ? true : false;
        */
    }
};
// @lc code=end
