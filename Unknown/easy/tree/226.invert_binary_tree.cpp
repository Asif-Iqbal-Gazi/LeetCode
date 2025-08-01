/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    TreeNode *invertTree(TreeNode *root)
    {
        /* Approach:
            1. Recursion -- T.C: O(n), S.C: O(n)
        */

        if (!root)
            return nullptr;
        TreeNode *leftHolder = root->left;
        TreeNode *rightHolder = root->right;
        root->left = invertTree(rightHolder);
        root->right = invertTree(leftHolder);
        return root;
    }
};
// @lc code=end
