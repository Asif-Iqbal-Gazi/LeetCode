/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

#define MAX_NODES 101

struct Node *cloneMap[MAX_NODES];

struct Node *dfs(struct Node *node) {
    if (!node)
        return NULL;
    if (cloneMap[node->val])
        return cloneMap[node->val];
    struct Node *clone  = (struct Node *)malloc(sizeof(struct Node));
    clone->val          = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors    = (struct Node **)malloc(node->numNeighbors * sizeof(struct Node *));
    cloneMap[node->val] = clone;
    for (int i = 0; i < node->numNeighbors; i++) clone->neighbors[i] = dfs(node->neighbors[i]);
    return clone;
}

struct Node *cloneGraph(struct Node *node) {
    /*
     * Approach:
     * 1. DFS + Hash Map -- T.C: O(V + E), S.C: O(V)
     *      - Recursively clone each node. Use a hash map to track already
     *        cloned nodes to avoid infinite loops in cyclic graphs.
     * 2. BFS + Hash Map -- T.C: O(V + E), S.C: O(V)
     *      - Clone nodes level by level using a queue.
     */

    // Approach 1 -- DFS
    memset(cloneMap, 0, sizeof(cloneMap));
    return dfs(node);

    /* Approach 2 -- BFS
    if (!node)
        return NULL;
    memset(cloneMap, 0, sizeof(cloneMap));
    struct Node *queue[MAX_NODES];
    int front = 0, back = 0;
    struct Node *clone     = (struct Node *)malloc(sizeof(struct Node));
    clone->val             = node->val;
    clone->numNeighbors    = node->numNeighbors;
    clone->neighbors       = (struct Node **)malloc(node->numNeighbors * sizeof(struct Node *));
    cloneMap[node->val]    = clone;
    queue[back++]          = node;
    while (front < back) {
        struct Node *curr = queue[front++];
        for (int i = 0; i < curr->numNeighbors; i++) {
            struct Node *neighbor = curr->neighbors[i];
            if (!cloneMap[neighbor->val]) {
                struct Node *neighborClone  = (struct Node *)malloc(sizeof(struct Node));
                neighborClone->val          = neighbor->val;
                neighborClone->numNeighbors = neighbor->numNeighbors;
                neighborClone->neighbors    = (struct Node **)malloc(neighbor->numNeighbors *
    sizeof(struct Node *)); cloneMap[neighbor->val]     = neighborClone; queue[back++] = neighbor;
            }
            cloneMap[curr->val]->neighbors[i] = cloneMap[neighbor->val];
        }
    }
    return cloneMap[node->val];
    */
}
