/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        /* Approach:
        1. Unordered_map --
            Using recursion traverse the tree and for each Node build a unique string of it's span
            Map this String, finally, checking the frequncies build the result vector
        */

        vector<TreeNode *> result;
        unordered_map<string, vector<TreeNode *>> map;

        // This helper function will do predorder traversal for each node and hash unique key
        traverseAndMap(root, map);
        // From the map check for a key if there are multiple entries
        for (auto it = map.begin(); it != map.end(); it++)
        {
            if (it->second.size() > 1)
                // Duplicate detected, push to result container
                result.emplace_back(it->second[0]);
        }
        return result;
    }

private:
    string traverseAndMap(TreeNode *node, unordered_map<string, vector<TreeNode *>> &map)
    { // Termination Case
        if (node == NULL)
            return "X";
        string s = "(" + to_string(node->val) + traverseAndMap(node->left, map) + traverseAndMap(node->right, map) + ")";
        map[s].emplace_back(node);
        return s;
    }
};
// @lc code=end
