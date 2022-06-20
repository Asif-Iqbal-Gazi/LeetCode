/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    /* Approach 1
    void inOrder(TreeNode *node, vector<int> &res)
    {
        if (!node)
            return;
        inOrder(node->left, res);
        res.emplace_back(node->val);
        inOrder(node->right, res);
    }
    */
    vector<int> inorderTraversal(TreeNode *root)
    {
        /* Approach:
        1. Recursion
        2. Iterative
        */

        // Approach 2
        vector<int> res;
        stack<TreeNode *> st;

        TreeNode *curr = root;

        while (curr || !st.empty())
        {
            while (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            res.emplace_back(curr->val);
            curr = curr->right;
        }
        return res;

        /* Approach 1
        vector<int> res;
        TreeNode *node = root;

        inOrder(node, res);
        return res;
        */
    }
};
// @lc code=end
