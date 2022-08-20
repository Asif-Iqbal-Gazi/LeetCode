/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        /* Approach
            1. BFS --
        */

        if (!root)
            return {};

        vector<vector<int>> ans;
        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            // Get size of Queue
            int n = q.size();
            vector<int> level;
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                level.emplace_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
// @lc code=end
