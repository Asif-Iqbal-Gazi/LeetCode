/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        /* Approach:
            1. DP (Bottom Up) -- T.C: O(m * n), S.C: O(m * n)
            2. DP (Space Optimised) -- T.C: O(m * n), S.C: O(1)
        */

        /*
            DP State:
                dp[i][j] = Path from (m-1, n-1) to (i, j) with minimum path sum
            DP Transition:
                dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i+1][j]
            Final Problem:
                dp[0][0]
            Base Case:
                dp[m-1][n-1] = 0
        */

        // Approach 2
        int m = grid.size();
        int n = grid[0].size();

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int minDown = (i + 1) < m ? grid[i + 1][j] : 1e6;
                int minRight = (j + 1) < n ? grid[i][j + 1] : 1e6;
                if (i == m - 1 && j == n - 1)
                    continue;
                grid[i][j] += min(minDown, minRight);
            }
        }

        return grid[0][0];

        /* Approach 1
        int m = grid.size();
        int n = grid[0].size();
        int dp[m + 1][n + 1];

        for(int i = m - 1; i >=0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(i == m - 1 && j == n -1)
                    dp[i][j] = grid[i][j];
                else {
                    int minDown = i + 1 < m ? dp[i + 1][j] : 1e6;
                    int minRight = j + 1 < n ? dp[i][j + 1] : 1e6;
                    dp[i][j] = grid[i][j] + min(minDown, minRight);
                }
            }
        }

        return dp[0][0];
        */
    }
};
// @lc code=end
