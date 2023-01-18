/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    // Approach 4
    int prev = INT_MIN;
    int maxCount = -1;
    int currCount = -1;

    vector<int> ans;
    void doInOrderTraversal(TreeNode *root)
    {
        // Base Case
        if (!root)
            return;
        doInOrderTraversal(root->left);
        // Figuring Out Mode
        if (root->val == prev)
            currCount++;
        else
        {
            currCount = 1;
            prev = root->val;
        }
        if (currCount > maxCount)
        {
            maxCount = currCount;
            ans = {root->val};
        }
        else if (currCount == maxCount)
            ans.push_back(root->val);

        doInOrderTraversal(root->right);
    }
    /* Approach 3
    void doInOrderTraversal(TreeNode *root, vector<int> &ds)
    {
        // Base Case
        if (!root)
            return;

        doInOrderTraversal(root->left, ds);
        ds.push_back(root->val);
        doInOrderTraversal(root->right, ds);
    }
    */
    /* Approach 1 & 2
    void doDFS(TreeNode *root, unordered_map<int, int> &mp)
    {
        // Base Case
        if (!root)
            return;
        // Insert into map
        mp[root->val]++;
        // Recursively call for children
        doDFS(root->left, mp);
        doDFS(root->right, mp);
    }
    */

public:
    vector<int> findMode(TreeNode *root)
    {
        /* Approach:
            1. Naive Method -- T.C: O(N), S.C: O(N)
                Use a unordered_map, BST properties not used
            2. Optimised Naive Method -- T.C: O(N), S.C: O(N)
                Single Pass in map
            3. Using inOrder Traversal -- T.C: O(N), S.C: O(N)
                With in order traversal build the sorted array (BST property)
                Then in O(N) figure out the mode(s).
            4. Using inOrder Traversal without the sorted array -- T.C: O(N), S.C: O(1)
        */

        // Approach 4
        doInOrderTraversal(root);
        return ans;

        /* Approach 3
        int prev = -1;
        int maxFreq = -1;
        int currCount = 1;
        vector<int> ds, ans;
        doInOrderTraversal(root, ds);
        for (auto x : ds)
        {
            if (x == prev)
                currCount++;
            else
            {
                currCount = 1;
                prev = x;
            }
            if (currCount == maxFreq)
                ans.push_back(x);
            else if (currCount > maxFreq)
            {
                maxFreq = currCount;
                ans = {x};
            }
        }
        return ans;
        */

        /* Approach 2
        int mFreq = -1;
        vector<int> ans;
        unordered_map<int, int> mp;
        doDFS(root, mp);
        // Traverse the map to get mode frequency and build ans
        for (auto item : mp)
        {
            if (item.second > mFreq)
            {
                mFreq = item.second;
                ans = {item.first};
            }
            else if (item.second == mFreq)
                ans.push_back(item.first);
        }

        return ans;
        */

        /* Approach 1
        int mFreq = 0;
        vector<int> ans;
        unordered_map<int, int> mp;
        doDFS(root, mp);
        // Traverse the map to get mode frequency
        for (auto item : mp)
            if (item.second > mFreq)
                mFreq = item.second;

        // Traverse the map again to build the ans
        for (auto item : mp)
            if (item.second == mFreq)
                ans.push_back(item.first);

        return ans;
        */
    }
};
// @lc code=end
