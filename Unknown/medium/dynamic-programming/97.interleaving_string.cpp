/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution
{
private:
    bool solveTopDown(int i, int j, string s1, string s2, string s3, vector<vector<int>> &dp)
    {
        if (i == s1.size() && j == s2.size())
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        bool op1 = false;
        bool op2 = false;
        if (s1[i] == s3[i + j])
            op1 = solveTopDown(i + 1, j, s1, s2, s3, dp);

        if (s2[j] == s3[i + j])
            op2 = solveTopDown(i, j + 1, s1, s2, s3, dp);

        return dp[i][j] = op1 | op2;
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        /* Approach:
            1. DP (Top Down) -- T.C: O(n * m), S.C: O(n * m)
            2. DP (Bottom Up) -- T.C: O(n * m), S.C: O(n * m)
            3. DP (Space Optimised) -- T.C: O(n * m). S.C: O(m)
        */

        /*
            DP State:
                dp[i][j] = Is it possible to construct s3 prefix of length (i+j), from interleaving of s1 prefix of length i and s2 prefix of length j

            DP Transition:
                if(i == 0 && j == 0) {
                    // Both s1 & s2 prefix empty
                    dp[i][j] = true;
                }
                else if(i == 0) {
                    // Only s1 prefix is empty, we need to check
                    dp[i][j] = (s2[j - 1] == s3[i + j - 1]) && dp[i][j - 1];
                }
                else if(j == 0) {
                    // Only s2 prefix is empty, we need to check
                    dp[i][j] = (s1[i - 1] == s3[i + j - 1]) && dp[i - 1][j];
                }
                else {
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                                | (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }

        */

        // Approach 3
        int n = s1.size();
        int m = s2.size();
        int len = s3.size();

        if (n + m != len)
            return false;
        vector<bool> prev(m + 1, false);
        vector<bool> curr(m + 1, false);

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 && j == 0)
                {
                    // Both s1 & s2 prefix empty
                    curr[j] = true;
                }
                else if (i == 0)
                {
                    // Only s1 prefix is empty, we need to check
                    curr[j] = (s2[j - 1] == s3[i + j - 1]) && curr[j - 1];
                }
                else if (j == 0)
                {
                    // Only s2 prefix is empty, we need to check
                    curr[j] = (s1[i - 1] == s3[i + j - 1]) && prev[j];
                }
                else
                {
                    curr[j] = (prev[j] && (s1[i - 1] == s3[i + j - 1])) |
                              (curr[j - 1] && (s2[j - 1] == s3[i + j - 1]));
                }
            }
            prev = curr;
        }

        return prev[m];

        /* Approach 2
        int n = s1.size();
        int m = s2.size();
        int len = s3.size();

        if(n + m != len)
            return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i == 0 && j == 0) {
                    // Both s1 & s2 prefix empty
                    dp[i][j] = true;
                }
                else if(i == 0) {
                    // Only s1 prefix is empty, we need to check
                    dp[i][j] = (s2[j - 1] == s3[i + j - 1]) && dp[i][j - 1];
                }
                else if(j == 0) {
                    // Only s2 prefix is empty, we need to check
                    dp[i][j] = (s1[i - 1] == s3[i + j - 1]) && dp[i - 1][j];
                }
                else {
                    dp[i][j] = (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) |
                               (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
                }
            }
        }

        return dp[n][m];
        */

        /* Approach 1
        int n = s1.size();
        int m = s2.size();
        int len = s3.size();

        if(n + m != len)
            return false;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solveTopDown(0, 0, s1, s2, s3, dp);
        */
    }
};
// @lc code=end
