/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
class Solution {
   public:
    vector<int> largestValues(TreeNode *root) {
        /* Approach:
            1. Level Order Traversal -- T.C: O(n), S.C: O(n)
        */

        // Approach 1 -- BFS (Level Order)
        if (!root) return {};
        vector<int> ans;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            int currMax = INT_MIN;

            for (int i = 0; i < sz; i++) {
                TreeNode *curr = q.front();
                q.pop();

                currMax = max(currMax, curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            ans.push_back(currMax);
        }
        return ans;
    }
};
// @lc code=end
