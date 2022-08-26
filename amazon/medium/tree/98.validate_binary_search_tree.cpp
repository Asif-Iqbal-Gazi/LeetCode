/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode *root, long minVal, long maxVal)
    {
        // Base Case
        if (!root)
            return true;
        if (root->val >= maxVal || root->val <= minVal)
            return false;
        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        /* Approach:
            1. Using Recursion -- O(N)
        */
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};
// @lc code=end
