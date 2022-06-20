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
    void postOrder(TreeNode *node, vector<int> &res)
    {
        if (!node)
            return;
        postOrder(node->left, res);
        postOrder(node->right, res);
        res.emplace_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        /* Approach :
        1. Recursion
        2. Iterative
        */

        // Approach 1
        vector<int> res;
        postOrder(root, res);
        return res;

        /* Approach 2
        vector<int> res;
        TreeNode *curr = root;
        stack<TreeNode *> st;

        while (curr || !st.empty())
        {
            while (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            curr = curr->right;
            res.emplace_back(curr->val);
        }
        return res;
        */
    }
};
// @lc code=end
