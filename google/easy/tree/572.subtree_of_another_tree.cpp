/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    bool isIdentical(TreeNode *root, TreeNode *subRoot)
    {
        if (!root && !subRoot)
            return true;
        if (!root || !subRoot)
            return false;
        /* Sweet and short replacement for above two if statement
        if(!root || !subRoot)
            return root == subRoot;
        */
        if (root->val != subRoot->val)
            return false;
        // Check recursively for children
        return isIdentical(root->left, subRoot->left) && isIdentical(root->right, subRoot->right);
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        /* Approach:
            1. Naive Method -- T.C: O(N*M), S.C: O(N+M)
                Level order wise check with every node from tree1 with tree2
            2. Naive Method (DFS) -- T.C: O(N*M), S.C: O(N+M)
        */

        // Approach 2
        if (!subRoot)
            return true;
        if (!root)
            return false;
        // If current node in tree1 & root of tree2 has same value, check if they are identical
        if (root->val == subRoot->val && isIdentical(root, subRoot))
            return true;
        // Recursively check for children of tree1
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

        /* Approach 1
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int q_sz = q.size();
            for (int i = 0; i < q_sz; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                // Now check if they are identical
                if (isIdentical(curr, subRoot))
                    return true;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }
        return false;
        */
    }
};
// @lc code=end
