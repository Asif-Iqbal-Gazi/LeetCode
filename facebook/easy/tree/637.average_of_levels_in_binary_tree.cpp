/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        /* Approach:
            1. Naive Method -- T.C: O(n), S.C: O(n)
        */

        // Approach 1
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            double sum = 0;
            int q_sz = q.size();
            TreeNode *curr = nullptr;
            for (int i = 0; i < q_sz; i++)
            {
                curr = q.front();
                sum += curr->val;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                q.pop();
            }
            double avg = sum / q_sz;
            ans.push_back(avg);
        }
        return ans;
    }
};
// @lc code=end
