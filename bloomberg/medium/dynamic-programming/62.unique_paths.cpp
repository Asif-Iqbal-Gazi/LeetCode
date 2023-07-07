/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        /* Approach:
            1. DP (Bottom Up) -- T.C: O(n * m), S.C: O(n * m)
            2. DP (Space Optimised) -- T.C: O(n * m), S.C: O(n)
        */

        // Approach 2
        vector<int> prev(n, 0), curr(n, 0);
        // Base Case
        curr[0] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i > 0)
                    curr[j] = prev[j];
                if (j > 0)
                    curr[j] += curr[j - 1];
            }
            prev = curr;
        }

        return curr[n - 1];

        /* Approach 1
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        // Base Case
        dp[m - 1][n - 1] = 1;

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(j < n - 1)
                    dp[i][j] += dp[i][j + 1];
                if(i < m - 1)
                    dp[i][j] += dp[i + 1][j];
            }
        }

        return dp[0][0];
        */
    }
};
// @lc code=end
