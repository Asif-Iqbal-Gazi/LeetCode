/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode *root) {
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
    int left  = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + (left > right ? left : right);

    /* Approach 2 -- Iterative BFS
    if (!root)
        return 0;
    struct TreeNode *queue[10001];
    int front = 0, back = 0, depth = 0;
    queue[back++] = root;
    while (front < back) {
        int size = back - front;
        for (int i = 0; i < size; i++) {
            struct TreeNode *node = queue[front++];
            if (node->left)  queue[back++] = node->left;
            if (node->right) queue[back++] = node->right;
        }
        depth++;
    }
    return depth;
    */
}
