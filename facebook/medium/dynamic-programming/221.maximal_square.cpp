/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution
{
private:
    /* Approach 2 -- DP (Top Down)
    int solveRec(int i, int j, int &maxLen, vector<vector<int>> &dp, vector<vector<char>> &matrix)
    {
        // Base Case
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = solveRec(i - 1, j, maxLen, dp, matrix);
        int left = solveRec(i, j - 1, maxLen, dp, matrix);
        int diag = solveRec(i - 1, j - 1, maxLen, dp, matrix);

        int curr = matrix[i][j] == '1' ? 1 : 0;
        int prev = min(diag, min(up, left));

        if (curr)
            curr += prev;

        if (maxLen < curr)
            maxLen = curr;

        return dp[i][j] = curr;
    }
    */

    /* Approach 1 -- Recursion
    int solveRec(int i, int j, int &maxLen, vector<vector<char>> &matrix)
    {
        // Base Case
        if (i < 0 || j < 0)
            return 0;

        int up = solveRec(i - 1, j, maxLen, matrix);
        int left = solveRec(i, j - 1, maxLen, matrix);
        int diag = solveRec(i - 1, j - 1, maxLen, matrix);

        int curr = matrix[i][j] == '1' ? 1 : 0;
        int prev = min(diag, min(up, left));

        if (curr)
            curr += prev;

        if (maxLen < curr)
            maxLen = curr;

        return curr;
    }
    */

public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        /* Approach:
            1. Recursion -- T.C: O(3^(n, m)), S.C: O(max(m, n))
            2. DP (Top Down) -- T.C: O(n * m), S.C: O(n * m)
            3. DP (Bottom Up) -- T.C: O(n * m), S.C: O(n * m)
            4. DP (Space Optimised) -- T.C: O(n * m), S.C: O(m)
        */

        // Approach 3 -- DP (Bottom Up)
        int maxLen = 0;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prev(m, 0);
        vector<int> curr(m, 0);

        // Set the base case

        for (int i = 0; i < m; i++)
        {
            prev[i] = matrix[0][i] - '0';
            maxLen = max(maxLen, prev[i]);
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                curr[j] = matrix[i][j] - '0';

                if (curr[j] && j > 0)
                    curr[j] += min(prev[j - 1], min(prev[j], curr[j - 1]));

                maxLen = max(maxLen, curr[j]);
            }
            prev = curr;
        }

        return maxLen * maxLen;

        /* Approach 3 -- DP (Bottom Up)
        int maxLen = 0;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Set the base case
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = matrix[i][0] - '0';
            maxLen = max(maxLen, dp[i][0]);
        }

        for (int j = 0; j < m; j++)
        {
            dp[0][j] = matrix[0][j] - '0';
            maxLen = max(maxLen, dp[0][j]);
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dp[i][j] = matrix[i][j] - '0';

                if (dp[i][j])
                    dp[i][j] += min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));

                maxLen = max(maxLen, dp[i][j]);
            }
        }

        return maxLen * maxLen;
        */

        /* Approach 2 -- DP (Top Down)
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxLen = 0;
        solveRec(n - 1, m - 1, maxLen, dp, matrix);
        return maxLen * maxLen;
        */

        /* Approach 1 -- Recursion
        int n = matrix.size();
        int m = matrix[0].size();
        int maxLen = 0;
        solveRec(n - 1, m - 1, maxLen, matrix);
        return maxLen * maxLen;
        */
    }
};
// @lc code=end
