/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    void doPostOrderTraversal(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;
        doPostOrderTraversal(root->left, ans);
        doPostOrderTraversal(root->right, ans);
        ans.emplace_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        /* Approach:
            1. Recursion -- T.C: O(n), S.C: O(h); n: No of node, h: height of the tree
            2. Iterative -- T.C: O(n), S.C: O(h)
        */

        // Approach 1
        vector<int> ans;
        doPostOrderTraversal(root, ans);
        return ans;
    }
};
// @lc code=end
