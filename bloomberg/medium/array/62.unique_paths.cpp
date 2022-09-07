/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution
{
private:
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i >= m || j >= n)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        else
            return dp[i][j] = solve(i + 1, j, m, n, dp) + solve(i, j + 1, m, n, dp);
    }

public:
    int uniquePaths(int m, int n)
    {
        /* Approach:
            1. Recursion -- T.C: O(2^n), S.C:O(M+N) -- Gets TLE
            2. DP -- T.C: O(m*n), S.C: O(m*n)
            3. Combinatorics -- T.C: O(min(m,n)), S.C: O(1)
                Awesome Idea :
                    Observe that to reach the destination we have to travel -
                    (n-1) times right
                    (m-1) times down
                    Also observe, for m = 2, n = 3, possible paths are
                    RRD, DRR, RDR
                    Basically, we have to choose either (m-1) or (n-1) from (m+n-2)
        */

        /* Approach 1 -- Recursion
        return solve(0, 0, m, n);
        */

        /* Approach 2 -- DP
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
        */

        // Approach 3 -- Combinatorics
        double res = 1;
        int N = m + n - 2;
        int r = min(m, n) - 1;

        for (int i = 1; i <= r; i++)
            res = res * (N - r + i) / i;

        return (int)res;
    }
};
// @lc code=end
