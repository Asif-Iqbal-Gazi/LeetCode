/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode *root) {
  if (!root)
    return 0;
  int left_tree  = maxDepth(root->left);
  int right_tree = maxDepth(root->right);
  return 1 + (left_tree > right_tree ? left_tree : right_tree);
}
