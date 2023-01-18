/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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
    int doDFS(TreeNode *root, int &tilt)
    {
        // Base Case
        if (!root)
            return 0;
        // Get left sum
        int lSum = doDFS(root->left, tilt);
        // Get right sum
        int rSum = doDFS(root->right, tilt);
        // Calculate tilt
        tilt += abs(lSum - rSum);
        // Return sum
        return lSum + rSum + root->val;
    }

public:
    int findTilt(TreeNode *root)
    {
        /* Approach:
            1. Recursion -- T.C: O(N), S.C: O(N)
        */

        if (!root)
            return 0;

        int ans = 0;
        doDFS(root, ans);
        return ans;
    }
};
// @lc code=end
