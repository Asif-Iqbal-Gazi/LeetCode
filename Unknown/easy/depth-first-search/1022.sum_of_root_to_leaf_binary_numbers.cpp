/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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
    int sumRootToLeaf(TreeNode *root, int sum)
    {
        if (!root)
            return 0;
        sum = (sum * 2) + root->val;
        if (!root->left && !root->right)
            return sum;
        return sumRootToLeaf(root->left, sum) + sumRootToLeaf(root->right, sum);
    }

public:
    int sumRootToLeaf(TreeNode *root)
    {
        return sumRootToLeaf(root, 0);
    }
};
// @lc code=end
