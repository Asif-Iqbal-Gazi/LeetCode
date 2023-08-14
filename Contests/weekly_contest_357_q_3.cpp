/*
    2812. Find the Safest Path in a Grid
    https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/
*/

class Solution {
   private:
    int N;
    bool visited[400][400];
    int safeMatrix[400][400];
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    bool doDFS(int r, int c, int minSafeFactor) {  // T.C: O(N^2)
        // Base Case
        if (r == N - 1 && c == N - 1) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int n_r = r + dx[i];
            int n_c = c + dy[i];
            bool inValidCell = n_r < 0 || n_r >= N || n_c < 0 || n_c >= N;
            if (inValidCell || visited[n_r][n_c] == 1) continue;
            visited[n_r][n_c] = 1;
            if (safeMatrix[n_r][n_c] < minSafeFactor) continue;
            if (doDFS(n_r, n_c, minSafeFactor))
                return true;
        }
        return false;
    }
    bool isValidPath(int minSafeFactor) {
        // Check if early exit possible
        if (safeMatrix[0][0] < minSafeFactor || safeMatrix[N - 1][N - 1] < minSafeFactor) {
            return false;
        }
        memset(visited, 0, sizeof(visited));
        // Using DFS check if we can reach (N - 1, N - 1)
        visited[0][0] = 1;
        return doDFS(0, 0, minSafeFactor);
    }

    int createManhattanDistanceMatrix(const vector<vector<int>>& grid) {
        // Multisource BFS
        int step = 0;
        int maxSafeFactor = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < N; i++) {  // T.C: O(N^2)
            for (int j = 0; j < N; j++) {
                if (grid[i][j]) {
                    safeMatrix[i][j] = 0;
                    q.push({i, j});
                } else {
                    safeMatrix[i][j] = INT_MAX;
                }
            }
        }
        // BFS (Level Order) -- T.C: O(V + 2E) == O(N^2)
        while (!q.empty()) {
            int sz = q.size();
            step++;
            for (int i = 0; i < sz; i++) {
                auto [r, c] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int n_r = r + dx[i];
                    int n_c = c + dy[i];
                    if (n_r < 0 || n_r >= N || n_c < 0 || n_c >= N || safeMatrix[n_r][n_c] <= step) continue;
                    safeMatrix[n_r][n_c] = step;
                    maxSafeFactor = max(step, maxSafeFactor);
                    q.push({n_r, n_c});
                }
            }
        }
        return maxSafeFactor;
    }

   public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        /* Approach:
            1. Multisource BFS + Binary Search + DFS -- T.C: O(n^2 log n), S.C: O(n^2)
        */
        N = grid.size();
        if (grid[0][0] || grid[N - 1][N - 1])
            return 0;

        int maxSafeFactor = createManhattanDistanceMatrix(grid);

        /*
        cout << "Safe Matrix" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << safeMatrix[i][j] << " ";
            }
            cout << "\n";
        }
        */

        // Now we have safeMatrix in which each cell has minimum manhatan
        // We can perform binary search to figure out the maximumSafenessFactor
        int l = 0, r = maxSafeFactor + 1;
        // We want max i s.t isValidPath(i) == True;
        // isValidPath(l) == True (always)
        // isValidPath(r) == False (always)

        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (isValidPath(m))
                l = m;
            else
                r = m;
        }
        return l;
    }
};