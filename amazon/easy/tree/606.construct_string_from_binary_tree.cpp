/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
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
    void tree2str(TreeNode *root, string &s)
    {
        if (!root)
        {
            s += "()";
            return;
        }
        s += to_string(root->val);
        if (!root->left && !root->right)
            return;
        s += "(";
        if (root->left)
            tree2str(root->left, s);
        s += ")";
        if (root->right)
        {
            s += "(";
            tree2str(root->right, s);
            s += ")";
        }
    }
    string tree2str(TreeNode *root)
    {
        /* Approach:
            1. Recursion -- T.C: O(N), S.C: O(N)
        */

        string ans;
        tree2str(root, ans);
        return ans;
    }
};
// @lc code=end
