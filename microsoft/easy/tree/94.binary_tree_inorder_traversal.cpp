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
    void doInOrderTraversal(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;
        doInOrderTraversal(root->left, ans);
        ans.emplace_back(root->val);
        doInOrderTraversal(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        /* Approach:
            1. Recursion -- T.C: O(n), S.C: O(h); n: No of node, h: height of the tree
            2. Iterative -- T.C: O(n), S.C: O(h)
        */

        /* Approach 1
        vector<int> ans;
        doInOrderTraversal(root, ans);
        return ans;
        */

        // Approach 2
        vector<int> ans;
        stack<TreeNode *> st;

        TreeNode *curr = root;

        while (curr || !st.empty())
        {
            while (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            // Out of loop, meaning we hit a NULL
            curr = st.top();
            st.pop();
            ans.emplace_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }
};
// @lc code=end
