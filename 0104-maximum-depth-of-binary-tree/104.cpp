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
class Solution {
public:
  int maxDepth(TreeNode *root) {
    /* Approach:
        1. Recursion -- T.C: O(n), S.C: O(n)
    */

    // Approach 1
    // Edge Case
    if (!root)
      return 0;
    return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
  }
};
