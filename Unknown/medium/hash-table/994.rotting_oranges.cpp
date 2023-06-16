/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        /* Approach:
            1. BFS -- T.C: O(n*m), S.C: O(n*m)
        */

        // Approach
        int n = grid.size();
        int m = grid[0].size();

        int time = 0;
        int freshCount = 0;
        int visited[n][m];
        queue<pair<int, int>> gridQueue;

        // Loop throught the grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    freshCount++;
                else if (grid[i][j] == 2)
                    gridQueue.push({i, j});

                visited[i][j] = grid[i][j];
            }
        }

        // Edge Cases
        if (freshCount == 0)
            return 0;
        if (gridQueue.size() == 0)
            return -1;

        int delta[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        while (!gridQueue.empty())
        {
            if (freshCount == 0)
                return time;
            int size = gridQueue.size();

            for (int i = 0; i < size; i++)
            {
                int curr_x = gridQueue.front().first;
                int curr_y = gridQueue.front().second;
                gridQueue.pop();
                for (int i = 0; i < 4; i++)
                {
                    int new_x = curr_x + delta[i][0];
                    int new_y = curr_y + delta[i][1];
                    if (new_x >= 0 && new_x < n &&
                        new_y >= 0 && new_y < m &&
                        visited[new_x][new_y] == 1)
                    {
                        freshCount--;
                        visited[new_x][new_y] = 2;
                        gridQueue.push({new_x, new_y});
                    }
                }
            }
            time++;
        }

        return freshCount == 0 ? time : -1;
    }
};
// @lc code=end
