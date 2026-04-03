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
#include <string>
class Solution {
  private:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        /* Sweet and short replacement for above two if statement
         if both are either is null, both needs to be null
        if (!p || !q)
            return p == q;

         */
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    void serialize(TreeNode *node, string& s) {
        if (!node) {
            s += "#,";
            return;
        }
        s += "," + std::to_string(node->val);
        serialize(node->left, s);
        serialize(node->right, s);
    }

  public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {

        /*
         * Approach:
         * 1. Recursive DFS -- T.C: O(M * N), S.C: O(M + N)
         *      - For each node in root, check if subRoot matches starting fromt that node.
         *      - M = nodes in root, N = nodes in subRoot
         * 2. Serialization -- T.C: O(M * N), S.C: O(M + N)
         *      - Serialize both trees into strings, then check if subRoot's
         *         serialization is a substring of root's serialization.
         *      - Use delimiters to avoid false matches e.g [12] matching [1] and [2]
         */

        // Approach 2 -- Serialization
        string rootStr, subStr;
        serialize(root, rootStr);
        serialize(subRoot, subStr);
        return rootStr.find(subStr) != string::npos;

        /* Approach 1 -- DFS
        if (!root)
            return false;
        if (isSameTree(root, subRoot))
            return true;
        return isSameTree(root->left, subRoot) || isSameTree(root->right, subRoot);
        */
    }
};
