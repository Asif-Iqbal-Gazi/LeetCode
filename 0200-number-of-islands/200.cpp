class Solution {
  private:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dfs(int r, int c, int m, int n, vector<vector<char>>& grid) {
        grid[r][c] = '2';
        int count  = 1;

        for (auto [dr, dc] : dirs) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != '1')
                continue;
            count += dfs(nr, nc, m, n, grid);
        }
        return count;
    }

  public:
    int numIslands(vector<vector<char>>& grid) {
        /*
         * Approach:
         * 1. DFS -- T.C: O(M * N), S.C: O(M * N)
         *      - When a '1' is found, increment count and sink the entire
         *        island via DFS by marking connected cells as '0'.
         * 2. BFS -- T.C: O(M * N), S.C: O(M * N)
         *      - Same logic as DFS but uses a queue for level-by-level traversal.
         */

        // Approach 2 - BFS
        int m       = grid.size();
        int n       = grid[0].size();
        int islands = 0;

        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '2';
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        for (auto [dr, dc] : dirs) {
                            int nr = r + dr;
                            int nc = c + dc;
                            if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != '1')
                                continue;
                            grid[nr][nc] = '2';
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
        return islands;

        /* Approach 1 - DFS
        int m       = grid.size();
        int n       = grid[0].size();
        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    int unit = dfs(i, j, m, n, grid);
                    // std::cout << "Current island has " << unit << " units\n";
                }
            }
        }
        return islands;
        */
    }
};
