/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
    void doDFS(TreeNode *curr, int low, int high, int &sum)
    {
        if (!curr)
            return;
        if (curr->val >= low && curr->val <= high)
            sum += curr->val;
        doDFS(curr->left, low, high, sum);
        doDFS(curr->right, low, high, sum);
    }

public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        /* Approach:
            1. Naive -- T.C: O(N), S.C: O(h)
                Traverse and Sum
            2. Utilise the property of BST -- T.C: O(N), S.C: O(h)

        */

        /* Approach 1
        int sum = 0;
        doDFS(root, low, high, sum);
        return sum;
        */

        // Approach 2
        if (!root)
            return 0;
        // If value of the node is less than 'low' no need to traverse left
        if (root->val < low)
            root->left = nullptr;
        // if value of the node is more than 'high' no need to traverse right
        if (root->val > high)
            root->right = nullptr;

        return (root->val >= low && root->val <= high ? root->val : 0) + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
// @lc code=end
