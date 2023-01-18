/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
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
    // Approach 2
    void findSecondMinimumValueHelper(TreeNode *root, int rootVal, long &ans)
    {
        // Base Case
        if (!root)
            return;
        if (rootVal < root->val && root->val < ans)
            ans = root->val;
        // Recursively call for children
        findSecondMinimumValueHelper(root->left, rootVal, ans);
        findSecondMinimumValueHelper(root->right, rootVal, ans);
    }

    /* Approach 1
    void doDFS(TreeNode *root, unordered_set<int> &s)
    {
        // Base Case
        if (!root)
            return;
        s.insert(root->val);
        // Recursively call for children
        doDFS(root->left, s);
        doDFS(root->right, s);
    }
    */

public:
    int findSecondMinimumValue(TreeNode *root)
    {
        /* Approach:
            1. Naive Method -- T.C: O(N), S.C: O(N)
                Use an unordered_set and do dfs
            2. Adhoc with out the set -- T.C: O(N), S.C: O(N)
        */

        // Approach 2
        long ans = LONG_MAX;
        int rootVal = root->val;
        findSecondMinimumValueHelper(root, rootVal, ans);
        return ans == LONG_MAX ? -1 : ans;

        /* Approach 1
        int ans = INT_MAX;
        int rootVal = root->val;
        unordered_set<int> s;
        doDFS(root, s);
        if (s.size() == 1)
            return -1;
        for (auto x : s)
        {
            if (x > rootVal && x < ans)
                ans = x;
        }
        return ans;
        */
    }
};
// @lc code=end
