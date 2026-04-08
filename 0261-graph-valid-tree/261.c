// for Union-Find
int root[2000];
int rank[2000];

int find(int x) {
    if (root[x] == x)
        return x;
    return root[x] = find(root[x]);
}

bool unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
        return false;
    if (rank[rootX] > rank[rootY])
        root[rootY] = rootX;
    else if (rank[rootX] < rank[rootY])
        root[rootX] = rootY;
    else {
        root[rootY] = rootX;
        rank[rootX]++;
    }
    return true;
}

bool doDFStoFindCycle(int curr, int parent, bool *visited, int *adjSize, int **adjList) {
    visited[curr] = true;

    for (int i = 0; i < adjSize[curr]; i++) {
        int nei = adjList[curr][i];
        if (!visited[nei]) {
            if (doDFStoFindCycle(nei, curr, visited, adjSize, adjList))
                return true;
        } else if (nei != parent)
            return true;
    }
    return false;
}

bool validTree(int n, int **edges, int edgesSize, int *edgesColSize) {
    /*
     * Approach:
     * 1. DFS        -- T.C: O(V + E),    S.C: O(V + E)
     *      - Build adjacency list, run DFS tracking visited and parent.
     *        Cycle = visited non-parent node. Check all visited for
     * connectivity.
     * 2. BFS        -- T.C: O(V + E),    S.C: O(V + E)
     *      - Same as DFS but level by level using a queue.
     * 3. Union Find -- T.C: O(E · α(V)), S.C: O(V)
     *      - For each edge, if both nodes share a root → cycle.
     *        After all edges, verify exactly n - 1 edges exist.
     */

    // Approach 3 -- Union Find
    if (edgesSize != n - 1)
        return false;

    // Initialize Union-Find
    for (int i = 0; i < n; i++) {
        root[i] = i;
        rank[i] = 1;
    }

    for (int i = 0; i < edgesSize; i++) {
        if (!unionSet(edges[i][0], edges[i][1]))
            return false;
    }
    return true;

    /* Approach 2 -- BFS
    if (edgesSize != n - 1)
        return false;

    int **adjList = (int **)calloc(n, sizeof(int *));
    int  *adjSize = (int *)calloc(n, sizeof(int));
    bool *visited = (bool *)calloc(n, sizeof(bool));

    // Build the adjacency list             // O(E)
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        adjList[u]               = realloc(adjList[u], (adjSize[u] + 1) * sizeof(int));
        adjList[v]               = realloc(adjList[v], (adjSize[v] + 1) * sizeof(int));
        adjList[u][adjSize[u]++] = v;
        adjList[v][adjSize[v]++] = u;
    }

    int connectedComponent = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            connectedComponent++;
            int queue[2001][2];
            int front      = 0;
            int back       = 0;
            queue[back][0] = i;
            queue[back][1] = -1;
            back++;

            while (front < back) {
                int curr   = queue[front][0];
                int parent = queue[front][1];
                front++;

                for (int i = 0; i < adjSize[curr]; i++) {
                    int nei = adjList[curr][i];
                    if (!visited[nei]) {
                        visited[nei]   = true;
                        queue[back][0] = nei;
                        queue[back][1] = curr;
                        back++;
                    } else if (nei != parent)
                        return false;
                }
            }
        }
    }
    return connectedComponent == 1;
    */

    /* Approach 1 -- DFS
    if (edgesSize != n - 1)
        return false;

    int **adjList = (int **)calloc(n, sizeof(int *));
    int  *adjSize = (int *)calloc(n, sizeof(int));
    bool *visited = (bool *)calloc(n, sizeof(bool));

    // Build the adjacency list             // O(E)
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        adjList[u]               = realloc(adjList[u], (adjSize[u] + 1) * sizeof(int));
        adjList[v]               = realloc(adjList[v], (adjSize[v] + 1) * sizeof(int));
        adjList[u][adjSize[u]++] = v;
        adjList[v][adjSize[v]++] = u;
    }

    int connectedComponent = 0;
    for (int i = 0; i < n; i++) { // O(V + 2E)
        if (!visited[i]) {
            connectedComponent++;
            if (doDFStoFindCycle(i, -1, visited, adjSize, adjList))
                return false;
        }
    }

    return connectedComponent == 1;
    */
}
