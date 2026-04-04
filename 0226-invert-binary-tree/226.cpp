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
    TreeNode *invertTree(TreeNode *root) {
        /*
         * Approach:
         * 1. Recursive DFS -- T.C: O(N), S.C: O(N)
         *      - Recursively invert left and right subtrees, then swap them.
         * 2. Iterative BFS -- T.C: O(N), S.C: O(N)
         *      - Use a queue to traverse level by level, swapping children at each node.
         */

        // Approach 1 -- Recursive DFS
        if (!root)
            return nullptr;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;

        /* Approach 2 -- Iterative BFS
        if (!root)
            return nullptr;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            swap(node->left, node->right);
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
        */
    }
};
