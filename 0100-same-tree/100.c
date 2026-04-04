#include <stdbool.h>

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
    /*
     * Approach:
     * 1. Recursive DFS -- T.C: O(N), S.C: O(N)
     *      - Recursively check if current nodes are equal, then verify
     *        left and right subtrees match.
     * 2. Iterative BFS -- T.C: O(N), S.C: O(N)
     *      - Use a queue to traverse both trees simultaneously,
     *        comparing nodes level by level.
     */

    // Approach 1 -- Recursive DFS
    /*
     * if (!p && !q)
     *     return true;
     * if (!p || !q)
     *     return false;
     * //This checks replaces the above to check
     * //If either of them is null, then both needs to be null
     */
    if (!p || !q)
        return p == q;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    /* Approach 2 -- Iterative BFS
    struct TreeNode *qp[201], *qq[201];
    int front = 0, back = 0;
    qp[back] = p;
    qq[back] = q;
    back++;
    while (front < back) {
        struct TreeNode *np = qp[front];
        struct TreeNode *nq = qq[front];
        front++;
        if (!np && !nq) continue;
        if (!np || !nq) return false;
        if (np->val != nq->val) return false;
        qp[back] = np->left;  qq[back] = nq->left;  back++;
        qp[back] = np->right; qq[back] = nq->right; back++;
    }
    return true;
    */
}
