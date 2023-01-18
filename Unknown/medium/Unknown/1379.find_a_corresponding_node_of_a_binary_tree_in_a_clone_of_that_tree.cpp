/*
 * @lc app=leetcode id=1379 lang=cpp
 *
 * [1379] Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
private:
    TreeNode *doDFS(TreeNode *curr, int val)
    {
        if (!curr)
            return nullptr;
        if (curr->val == val)
            return curr;
        TreeNode *left = doDFS(curr->left, val);
        if (left)
            return left;
        TreeNode *right = doDFS(curr->right, val);
        if (right)
            return right;
        return nullptr;
    }

public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        /* Approach:
            1. Naive -- T.C: O(N), S.C: O(h), height of the binary tree
                Traverse Cloned tree and heck for value.
        */

        int val = target->val;
        return doDFS(cloned, val);
    }
};
// @lc code=end
