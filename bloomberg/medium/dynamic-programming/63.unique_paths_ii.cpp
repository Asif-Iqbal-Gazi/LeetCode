/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        /* Approach:
            1. DP (Bottom Up) -- T.C: O(n * m), S.C: O(n * m)
            2. DP (Space Optimised) -- T.C: O(n * m), S.C: O(m)
        */

        // Approach 2
        // Edge Case
        if (obstacleGrid[0][0] == 1)
            return 0;

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<int> curr(m, 0), prev(m, 0);

        // Base Case
        curr[0] = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    curr[j] = 0;
                    continue;
                }
                if (i > 0)
                    curr[j] = prev[j];
                if (j > 0)
                    curr[j] += curr[j - 1];
            }
            prev = curr;
        }

        return prev[m - 1];

        /* Approach 1
        // Edge Case
        if(obstacleGrid[0][0] == 1)
            return 0;

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base Case
        dp[0][0] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(obstacleGrid[i][j] == 1) continue;
                if(i > 0)
                    dp[i][j] += dp[i - 1][j];
                if(j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
        */
    }
};
// @lc code=end
