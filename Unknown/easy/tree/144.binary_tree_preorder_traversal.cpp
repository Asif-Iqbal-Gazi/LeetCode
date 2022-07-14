/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    void doPreOrderTraversalRecursion(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        ans.push_back(root->val);
        doPreOrderTraversalRecursion(root->left, ans);
        doPreOrderTraversalRecursion(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        /* Approach:
            1. Recursion -- T.C: O(n), S.C: O(h); n: No of node, h: height of the tree
        */

        if (!root)
            return {};
        vector<int> ans;
        doPreOrderTraversalRecursion(root, ans);
        return ans;
    }
};
// @lc code=end
