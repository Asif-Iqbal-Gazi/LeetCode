#include <queue>
class Solution {
  public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        /*
         * Approach:
         *    1. Multi-Source BFS -- T.C: O(M * N), S.C: O(M * N)
         *      - Enqueue all gates simultaneously, expand outward level by level.
         *      - Each empty room is visited only once.
         */

        const int INF = 2147483647;
        int       m   = rooms.size();
        int       n   = rooms[0].size();

        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0)
                    q.push({i, j});
            }
        }

        int level     = 0;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [r, c] = q.front();
                q.pop();
                for (auto [dr, dc] : dir) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || rooms[nr][nc] != INF)
                        continue;
                    rooms[nr][nc] = rooms[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};
