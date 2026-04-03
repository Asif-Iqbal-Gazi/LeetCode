/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;
    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

void serialize(struct TreeNode *node, char *s) {
    if (!node) {
        strcat(s, ",#");
        return;
    }
    char buf[16];
    snprintf(buf, sizeof(buf), ",%d", node->val);
    strcat(s, buf);
    serialize(node->left, s);
    serialize(node->right, s);
}

bool isSubtree(struct TreeNode *root, struct TreeNode *subRoot) {
    /*
     * Approach:
     * 1. Recursive DFS -- T.C: O(M * N), S.C: O(M + N)
     *      - For each node in root, check if subRoot matches starting from that node.
     *      - M = nodes in root, N = nodes in subRoot
     * 2. Serialization -- T.C: O(M + N), S.C: O(M + N)
     *      - Serialize both trees into strings, then check if subRoot's
     *        serialization is a substring of root's serialization.
     *      - Use delimiters to avoid false matches e.g [12] matching [2]
     */

    // Approach 2 -- Serialization
    char rootStr[8192] = "";
    char subStr[4096]  = "";
    serialize(root, rootStr);
    serialize(subRoot, subStr);
    return strstr(rootStr, subStr) != NULL;

    /* Approach 1 -- DFS
    if (!root)
        return false;
    if (isSameTree(root, subRoot))
        return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    */
}
