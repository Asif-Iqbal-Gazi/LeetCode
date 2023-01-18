/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode *helper(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        TreeNode *curr = new TreeNode(nums[mid]);
        curr->left = helper(nums, left, mid - 1);
        curr->right = helper(nums, mid + 1, right);
        return curr;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        /* Approach:
            1. Recursion -- T.C: O(n), S.C: O(n)
        */

        return helper(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
