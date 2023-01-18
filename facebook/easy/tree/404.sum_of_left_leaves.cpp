/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    void doDFS(TreeNode *root, bool isLeft, int &sum)
    {
        // Base case
        if (!root)
            return;
        // If left leaf node
        if (isLeft && !root->left && !root->right)
            sum += root->val;
        // Recursively check for children
        doDFS(root->left, true, sum);
        doDFS(root->right, false, sum);
    }

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        /* Approach:
            1. Recursion -- T.C: O(N), S.C: O(N)
        */

        int sum = 0;
        doDFS(root, false, sum);
        return sum;
    }
};
// @lc code=end
