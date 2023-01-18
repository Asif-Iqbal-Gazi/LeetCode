/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    int heightOfTree(TreeNode *root)
    {
        // Base Case
        if (!root)
            return 0;
        int lHeight = heightOfTree(root->left);
        int rHeight = heightOfTree(root->right);
        // Check if either one is -1 then return -1 as well
        if (lHeight == -1 || rHeight == -1)
            return -1;
        // If absolute difference between left and right height is more than 1 return -1
        if (abs(lHeight - rHeight) > 1)
            return -1;
        // Otherwise return the actual height
        return 1 + max(lHeight, rHeight);
    }

public:
    bool isBalanced(TreeNode *root)
    {
        /* Approach:
            1. Recursion -- T.C: O(N), S.C: O(N)
                Post order traversal, if valid then pass the height other wise pass -1
        */

        int height = heightOfTree(root);
        return height == -1 ? false : true;
    }
};
// @lc code=end
