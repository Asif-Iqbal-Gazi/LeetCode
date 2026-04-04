/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *invertTree(struct TreeNode *root) {
    /*
     * Approach:
     * 1. Recursive DFS -- T.C: O(N), S.C: O(N)
     *      - Recursively invert left and right subtrees, then swap them.
     * 2. Iterative BFS -- T.C: O(N), S.C: O(N)
     *      - Use a queue to traverse level by level, swapping children at each node.
     */

    // Approach 1 -- Recursive DFS
    if (!root)
        return NULL;
    struct TreeNode *temp = root->left;
    root->left            = invertTree(root->right);
    root->right           = invertTree(temp);
    return root;

    /* Approach 2 -- Iterative BFS
    if (!root)
        return NULL;
    struct TreeNode *queue[101];
    int front = 0, back = 0;
    queue[back++] = root;
    while (front < back) {
        struct TreeNode *node = queue[front++];
        struct TreeNode *temp = node->left;
        node->left            = node->right;
        node->right           = temp;
        if (node->left)  queue[back++] = node->left;
        if (node->right) queue[back++] = node->right;
    }
    return root;
    */
}
