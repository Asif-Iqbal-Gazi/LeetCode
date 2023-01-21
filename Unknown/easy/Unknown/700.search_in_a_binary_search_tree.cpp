/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
 */

// @lc code=start
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        /* Approach:
            1. Recursion -- T.C: O(N), S.C: O(h); N : Total Number of nodes, h : Height of the tree
            2. Iterative -- T.C: O(N), S.C: O(1)
        */

        // Approach 2
        TreeNode *curr = root;

        while (curr && curr->val != val)
        {
            if (curr->val > val)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return curr;

        /* Approach 1
        // Base Case
        if (!root)
            return NULL;
        if (root->val == val)
            return root;
        else if (root->val < val)
            return searchBST(root->right, val);
        else
            return searchBST(root->left, val);
        */
    }
};
// @lc code=end
