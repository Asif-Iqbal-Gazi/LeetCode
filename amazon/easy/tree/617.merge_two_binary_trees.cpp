/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        /* Approach
            1. Recursion without creating new node -- T.C: O(m), S.C: O(m), minimum nodes in both the tree
            2. Recursion with creating new node -- T.C: O(m), S.C: O(m)
        */

        // Approach 2
        if (!root1 && !root2)
            return nullptr;

        int val1 = root1 ? root1->val : 0;
        int val2 = root2 ? root2->val : 0;

        TreeNode *t = new TreeNode(val1 + val2);

        t->left = mergeTrees(root1 ? root1->left : nullptr, root2 ? root2->left : nullptr);
        t->right = mergeTrees(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr);
        return t;

        /* Approach 1
        if (!root1)
            return root2;
        if (!root2)
            return root1;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
        */
    }
};
// @lc code=end
