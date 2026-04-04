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
        /*
         * Approach:
         * 1. Recursive DFS -- T.C: O(N), S.C: O(N)
         *      - Depth at current node is 1 + max(left, right).
         *        Base case: null node returns 0.
         * 2. Iterative BFS -- T.C: O(N), S.C: O(N)
         *      - Traverse level by level, incrementing depth counter
         *        for each level processed.
         */

        // Approach 1 -- Recursive DFS
        if (!root)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));

        /* Approach 2 -- Iterative BFS
        if (!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }
        return depth;
        */
    }
};
