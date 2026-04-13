#include <stdlib.h>

void wallsAndGates(int **rooms, int roomsSize, int *roomsColSize) {
    /*
     * Approach:
     * 1. Multi-Source BFS -- T.C: O(M * N), S.C: O(M * N)
     *      - Enqueue all gates simultaneously, expand outward level by level.
     *      - Each empty room is visited only once.
     */
    const int INF      = 2147483647;
    int       m        = roomsSize;
    int       n        = roomsColSize[0];
    int      *queueR   = (int *)malloc(m * n * sizeof(int));
    int      *queueC   = (int *)malloc(m * n * sizeof(int));
    int       head     = 0;
    int       tail     = 0;
    int       size     = 0;
    int       capacity = m * n;

    // Enqueue all gates
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (rooms[r][c] == 0) {
                queueR[tail] = r;
                queueC[tail] = c;
                tail         = (tail + 1) % capacity;
                size++;
            }
        }
    }

    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (size) {
        int r = queueR[head];
        int c = queueC[head];
        head  = (head + 1) % capacity;
        size--;
        for (int j = 0; j < 4; j++) {
            int nr = r + dir[j][0];
            int nc = c + dir[j][1];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n || rooms[nr][nc] != INF)
                continue;
            rooms[nr][nc] = rooms[r][c] + 1;
            queueR[tail]  = nr;
            queueC[tail]  = nc;
            tail          = (tail + 1) % capacity;
            size++;
        }
    }
    free(queueR);
    free(queueC);
}
