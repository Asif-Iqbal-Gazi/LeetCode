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
    /* Approach 1
    void preOrder(TreeNode *node, vector<int> &res)
    {
        if (!node)
            return;
        res.emplace_back(node->val);
        preOrder(node->left, res);
        preOrder(node->right, res);
    }
    */
    vector<int> preorderTraversal(TreeNode *root)
    {
        /* Approach:
        1. Recursion
        2. Iterative
        */

        // Approach 2
        vector<int> res;
        TreeNode *curr = root;
        stack<TreeNode *> st;

        while (curr || !st.empty())
        {
            while (curr)
            {
                res.emplace_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            curr = curr->right;
        }
        return res;

        /* Approach 1
        vector<int> res;
        preOrder(root, res);
        return res;
        */
    }
};
// @lc code=end
