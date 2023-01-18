/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
    void doDFS(TreeNode *root, int &ans, int &pre)
    {
        if (root->left)
            doDFS(root->left, ans, pre);
        if (pre >= 0)
            ans = min(ans, root->val - pre);
        pre = root->val;
        if (root->right)
            doDFS(root->right, ans, pre);
    }
    void doInOrderTraversal(TreeNode *root, vector<int> &nums)
    {
        // Base Case
        if (!root)
            return;
        doInOrderTraversal(root->left, nums);
        nums.push_back(root->val);
        doInOrderTraversal(root->right, nums);
    }

public:
    int getMinimumDifference(TreeNode *root)
    {

        /* Approach:
            1. Naive Method -- T.C: O(N), S.C: O(N)
                Build sorted array, check there
            2. Recursion -- T.C: O(N), S.C: O(N)
        */

        // Approach 2
        int pre = -1;
        int ans = INT_MAX;
        doDFS(root, ans, pre);
        return ans;

        /* Approach 1
        int ans = INT_MAX;
        vector<int> nums;
        doInOrderTraversal(root, nums);
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int currDiff = nums[i] - prev;
            ans = min(ans, currDiff);
            if (currDiff == 1)
                return 1;
            prev = nums[i];
        }
        return ans;
        */
    }
};
// @lc code=end
