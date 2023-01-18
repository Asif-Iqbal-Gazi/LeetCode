/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
    void doInOrderTraversal(TreeNode *root, vector<int> &nums)
    {
        // Base case
        if (!root)
            return;
        doInOrderTraversal(root->left, nums);
        nums.push_back(root->val);
        doInOrderTraversal(root->right, nums);
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        /* Approach:
            1. Naive Method -- T.C: O(N), S.C: O(N)
                Build the sorted array, then two pointers.
            2. Level Order Traversal + Unordered_Set -- T.C: O(N), S.C: O(N)
        */

        // Approach 2
        queue<TreeNode *> q;
        unordered_set<int> s;

        q.push(root);

        while (!q.empty())
        {
            int q_sz = q.size();
            for (int i = 0; i < q_sz; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (s.find(k - curr->val) != s.end())
                    return true;
                s.insert(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }
        return false;

        /* Approach 1
        vector<int> nums;
        doInOrderTraversal(root, nums);
        int l = 0;
        int r = nums.size() - 1;

        int sum;
        while (l < r)
        {
            sum = nums[l] + nums[r];
            if (sum == k)
                return true;
            else if (sum > k)
                r--;
            else
                l++;
        }
        return false;
        */
    }
};
// @lc code=end
