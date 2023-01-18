/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
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
    void doInOrderTraversal(TreeNode *curr, vector<TreeNode *> &ds)
    {
        if (!curr)
            return;
        doInOrderTraversal(curr->left, ds);
        ds.push_back(curr);
        doInOrderTraversal(curr->right, ds);
    }

public:
    TreeNode *increasingBST(TreeNode *root)
    {
        /* Approach:
            1. Naive Method -- T.C: O(n), S.C: O(n)
                Produce a vector by inorder traversal, then produce the tree with the vector
            2. Naive Method (Modifying existing tree) -- T.C: O(n), S.C: O(n)
        */

        // Approach 2
        vector<TreeNode *> ans;
        doInOrderTraversal(root, ans);
        int i;
        for (i = 0; i < ans.size() - 1; i++)
        {
            ans[i]->right = ans[i + 1];
            ans[i]->left = nullptr;
        }
        ans[i]->left = nullptr;
        ans[i]->right = nullptr;
        return ans[0];

        /* Approach 1
        if (!root)
            nullptr;
        vector<int> ds;
        doInOrderTraversal(root, ds);
        TreeNode *newRoot = new TreeNode(ds[0]);
        TreeNode *temp = newRoot;
        for (int i = 1; i < ds.size(); i++)
        {
            TreeNode *curr = new TreeNode(ds[i]);
            temp->right = curr;
            temp = temp->right;
        }
        return newRoot;
        */
    }
};
// @lc code=end
