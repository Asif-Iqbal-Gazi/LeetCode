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
private:
  vector<TreeNode *> buildAllTrees(int start, int end) {
    // Base Case: no nodes in this range
    if (start > end)
      return {nullptr};

    vector<TreeNode *> allTrees;
    for (int rootVal = start; rootVal <= end; rootVal++) {
      // Recursively build all left and right subtrees
      vector<TreeNode *> leftSubtrees  = buildAllTrees(start, rootVal - 1);
      vector<TreeNode *> rightSubtrees = buildAllTrees(rootVal + 1, end);

      // Combine each pair of left and right subtree with current root
      for (TreeNode *left : leftSubtrees) {
        for (TreeNode *right : rightSubtrees) {
          TreeNode *root = new TreeNode(rootVal);
          root->left     = left;
          root->right    = right;
          allTrees.push_back(root);
        }
      }
    }
    return allTrees;
  }

public:
  vector<TreeNode *> generateTrees(int n) {
    /* Approach:
       1. [Recursion] -- T.C: O(n * C(n)), S.C: O(n * C(n)); C(n): nth Catalan Number
        - For each root value from start to end, recursively build all left and right subtree.
        - Combine all possible left-rigth subtree pairs to form unqiue BSTs.
        - Total number of unique trees formed is given by the Catalan number C(n).
    */
    return buildAllTrees(1, n);
  }
};
