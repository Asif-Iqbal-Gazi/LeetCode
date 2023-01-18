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
    bool isValidBST(TreeNode *root, long maxVal, long minVal)
    {
        if (!root)
            return true;

        if (root->val >= maxVal || root->val <= minVal)
            return false;
        return isValidBST(root->left, root->val, minVal) &&
               isValidBST(root->right, maxVal, root->val);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        /* Approach:
            1. Recursion -- T.C: O(N), S.C: O(h), h: height of the binary tree
        */

        return isValidBST(root, LONG_MAX, LONG_MIN);
    }
};
// @lc code=end
