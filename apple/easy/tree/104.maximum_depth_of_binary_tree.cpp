/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    void findMaxDepth(TreeNode *root, int depth, int &ans)
    {
        if (!root)
            return;
        if (root->left == NULL && root->right == NULL)
        { // Leaf Node
            ans = max(depth, ans);
        }
        findMaxDepth(root->left, depth + 1, ans);
        findMaxDepth(root->right, depth + 1, ans);
    }
    int maxDepth(TreeNode *root)
    {
        /* Approach :
            Recursion -- T.C: O(n), S.C: O(h)
        */

        int ans = 0;
        findMaxDepth(root, 1, ans);
        return ans;
    }
};
// @lc code=end
