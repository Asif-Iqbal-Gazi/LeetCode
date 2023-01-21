/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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
private:
    void deepestLeavesSumHelper(TreeNode *root, int currDepth, int &maxDepth, int &ans)
    {
        // Base Case
        if (!root)
            return;
        currDepth++;
        // Check if we are at leaf node
        if (!root->left && !root->left)
        {
            if (currDepth > maxDepth)
            {
                ans = root->val;
                maxDepth = currDepth;
            }
            else if (currDepth == maxDepth)
                ans += root->val;
        }
        // Recursively call for children
        deepestLeavesSumHelper(root->left, currDepth, maxDepth, ans);
        deepestLeavesSumHelper(root->right, currDepth, maxDepth, ans);
    }

public:
    int deepestLeavesSum(TreeNode *root)
    {
        /* Approach :
            1. Simple DFS -- T.C: O(N), S.C: O(N)
            2. Simple BFS -- T.C: O(N), S.C: O(N)
        */

        // Approach 2
        int ans = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            ans = 0;
            int q_sz = q.size();
            for (int i = 0; i < q_sz; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                ans += curr->val;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }
        return ans;

        /* Approach 1
        int ans = 0;
        int maxDepth = 0;
        deepestLeavesSumHelper(root, 0, maxDepth, ans);
        return ans;
        */
    }
};
// @lc code=end
