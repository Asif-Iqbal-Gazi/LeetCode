/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        /* Approach :
            1. BFS -- T.C: O(n), S.C: O(n)
        */

        // Approach 1
        // Base Case
        if (grid[0][0] == 1)
            return -1;
        int n = grid.size();
        if (n == 1)
            return n;

        int ans = 1;
        queue<pair<int, int>> pathQ;
        int delta[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        pathQ.push({0, 0});
        grid[0][0] = 2;

        while (!pathQ.empty())
        {
            ans++;
            int size = pathQ.size();

            for (int i = 0; i < size; i++)
            {
                int x = pathQ.front().first;
                int y = pathQ.front().second;
                pathQ.pop();
                for (int i = 0; i < 8; i++)
                {
                    int dx = x + delta[i][0];
                    int dy = y + delta[i][1];
                    if (dx >= 0 && dx < n && dy >= 0 && dy < n && grid[dx][dy] == 0)
                    {
                        if (dx == (n - 1) && dy == (n - 1))
                            return ans;
                        grid[dx][dy] = 2; // Marking visited
                        pathQ.push({dx, dy});
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end
