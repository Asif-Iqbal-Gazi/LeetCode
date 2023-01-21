/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        /* Approach:
            1. Recursion -- T.C: O(N), S.C: O(N)
            2. Iterative -- T.C: O(N), S.C: O(1)
        */

        // Approach 2
        TreeNode *curr = root;

        while (curr)
        {
            if (val > curr->val)
            {
                // Go Right
                if (!curr->right)
                {
                    curr->right = new TreeNode(val);
                    return root;
                }
                else
                    curr = curr->right;
            }
            else
            {
                // Go Left
                if (!curr->left)
                {
                    curr->left = new TreeNode(val);
                    return root;
                }
                else
                    curr = curr->left;
            }
        }
        return new TreeNode(val);

        /* Approach 1
        if (!root)
            return new TreeNode(val);

        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        else
            root->left = insertIntoBST(root->left, val);
        return root;
        */
    }
};
// @lc code=end
