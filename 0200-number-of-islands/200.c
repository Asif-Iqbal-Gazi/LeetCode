#include <stdlib.h>
int dfs(int r, int c, int m, int n, char **grid) {
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1')
        return 0;
    // mark visited
    grid[r][c] = '2';
    int count  = 1;
    count += dfs(r, c + 1, m, n, grid);
    count += dfs(r + 1, c, m, n, grid);
    count += dfs(r, c - 1, m, n, grid);
    count += dfs(r - 1, c, m, n, grid);
    return count;
}

int numIslands(char **grid, int gridSize, int *gridColSize) {
    /*
     * Approach:
     * 1. DFS -- T.C: O(M * N), S.C: O(M * N)
     *      - When a '1' is found, increment count and sink the entire
     *        island via DFS by marking connected cells as '0'.
     * 2. BFS -- T.C: O(M * N), S.C: O(M * N)
     *      - Same logic as DFS but uses a queue for level-by-level traversal.
     */

    // Approach 2 - BFS
    int m       = gridSize;
    int n       = gridColSize[0];
    int islands = 0;

    int *queueR   = (int *)malloc(m * n * sizeof(int));
    int *queueC   = (int *)malloc(m * n * sizeof(int));
    int  head     = 0;
    int  tail     = 0;
    int  size     = 0;
    int  capacity = n * m;

    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                grid[i][j] = '2';
                islands++;
                queueR[tail] = i;
                queueC[tail] = j;
                tail         = (tail + 1) % capacity;
                size++;

                while (size) {
                    int r = queueR[head];
                    int c = queueC[head];
                    head  = (head + 1) % capacity;
                    size--;

                    for (int k = 0; k < 4; k++) {
                        int nr = r + dir[k][0];
                        int nc = c + dir[k][1];
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != '1')
                            continue;
                        grid[nr][nc] = '2';
                        queueR[tail] = nr;
                        queueC[tail] = nc;
                        tail         = (tail + 1) % capacity;
                        size++;
                    }
                }
            }
        }
    }
    free(queueR);
    free(queueC);
    return islands;

    /* Approach 1 - DFS
    int m       = gridSize;
    int n       = gridColSize[0];
    int islands = 0;

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == '1') {
                islands++;
                int unit = dfs(r, c, m, n, grid);
                // printf("Current island: %d units.\n", unit);
            }
        }
    }

    return islands;
    */
}
