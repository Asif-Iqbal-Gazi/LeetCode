/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
    void doDFS(TreeNode *root, vector<int> &ds)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
            ds.push_back(root->val);
        doDFS(root->left, ds);
        doDFS(root->right, ds);
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        /* Approach:
            1. Naive Mehod -- T.C: O(max(n,m)), S.C: O(n+m)
                Store the leaf nodes in a container and compare
        */

        vector<int> ds1, ds2;

        doDFS(root1, ds1);
        doDFS(root2, ds2);

        int n = ds1.size();

        if (ds1.size() != ds2.size())
            return false;

        for (int i = 0; i < n; i++)
            if (ds1[i] != ds2[i])
                return false;
        return true;
    }
};
// @lc code=end
