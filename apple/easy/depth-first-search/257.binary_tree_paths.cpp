/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    void binaryTreePaths(TreeNode *root, string s, vector<string> &ans)
    {
        // Base Case
        if (!root)
            return;
        // Extract value
        s += to_string(root->val);
        // Add '->' if children is present
        if (root->left || root->right)
            s += "->";
        // If leaf node then push path to ans;
        if (!root->left && !root->right)
        {
            ans.push_back(s);
            return;
        }
        // Recursively call other branch
        binaryTreePaths(root->left, s, ans);
        binaryTreePaths(root->right, s, ans);
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        /* Approach:
            1. Recursion -- T.C: O(N), S.C: O(N)
        */

        vector<string> ans;
        binaryTreePaths(root, "", ans);
        return ans;
    }
};
// @lc code=end
