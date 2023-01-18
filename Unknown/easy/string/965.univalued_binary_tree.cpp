/*
 * @lc app=leetcode id=965 lang=cpp
 *
 * [965] Univalued Binary Tree
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
    bool isUnivalTree(TreeNode *root)
    {
        /* Approach :
            1. Recursion -- T.C: O(n), S.C: O(n)
        */

        if (!root)
            return true;
        if (root->left && root->val != root->left->val)
            return false;
        if (root->right && root->val != root->right->val)
            return false;
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
// @lc code=end
