/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int findDiameter(TreeNode *root, int &ans)
    {
        // Base Case
        if (!root)
            return 0;
        int lHeight = findDiameter(root->left, ans);
        int rHeight = findDiameter(root->right, ans);
        // Calculate the diameter
        ans = max(ans, rHeight + lHeight);
        return 1 + max(lHeight, rHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        /* Approach:
            1. Recursion -- T.C: O(N), S.C: O(N)
                Find left and right height for a node and then calculate the diameter
        */

        int ans = 0;
        findDiameter(root, ans);
        return ans;
    }
};
// @lc code=end
