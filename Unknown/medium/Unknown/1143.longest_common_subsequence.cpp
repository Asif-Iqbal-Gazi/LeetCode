/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution
{
private:
    /* Approach 2
    int solveTopDown(int ind1, int ind2, const string &s1, const string &s2, vector<vector<int>> &dp)
    {
        // Base Case
        if (ind1 == s1.size() || ind2 == s2.size())
            return 0;

        int &ans = dp[ind1][ind2];
        if (ans != -1)
            return ans;

        // Option 1 -- Matched
        if (s1[ind1] == s2[ind2])
            ans = 1 + solveTopDown(ind1 + 1, ind2 + 1, s1, s2, dp);
        // Option 2 -- Not Matched
        else
            ans = max(solveTopDown(ind1 + 1, ind2, s1, s2, dp),
                      solveTopDown(ind1, ind2 + 1, s1, s2, dp));
        return ans;
    }
    */

    /* Approach 1
    int solveRec(int ind1, int ind2, const string &s1, const string &s2)
    {
        // Base Case
        if (ind1 == s1.size() || ind2 == s2.size())
            return 0;

        // Option 1 -- Matched
        if (s1[ind1] == s2[ind2])
            return 1 + solveRec(ind1 + 1, ind2 + 1, s1, s2);
        // Option 2 -- Not Matched
        return max(solveRec(ind1 + 1, ind2, s1, s2),
                   solveRec(ind1, ind2 + 1, s1, s2));
    }
    */

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        /* Approach:
            1. Recursion -- T.C: O(2^n + 2^m), S.C: O(n + m)
            2. DP (Top Down) -- T.C: O(n * m), S.C: O(n * m)
            3. DP (Bottom Up) -- T.C: O(n * m), S.C: O(n * m)
            4. DP (Space Optimised) -- T.C: O(n * m), S.C: O(m)
        */

        // Approach 4 -- DP (Space Optimised)
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                    curr[j] = 1 + prev[j + 1];
                else
                    curr[j] = max(prev[j], curr[j + 1]);
            }
            prev = curr;
        }

        return prev[0];

        /* Approach 3 -- DP (Bottom Up)
        // * DP State:
        //     dp(i, j) = Longest Common Subsequences in text1[i:n] & text2[j:m]
        // * State Transition:
        //     dp(i, j) = {
        //         if(text1[i] == text2[j]) then 1 + dp(i+1, j+1)
        //         else max(dp(i+1, j), dp(i, j+1))
        //     }
        // * Base Case:
        //     dp(i, j) = 0 for all i = text1.size() and any j
        //                 or for j = text2.size() and any i
        // * Final Answer:
        //     dp(0, 0)

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return dp[0][0];
        */

        /* Approach 2 -- DP (Top Down)
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solveTopDown(0, 0, text1, text2, dp);
        */

        /* Approach 1 -- Recursion
        return solveRec(0, 0, text1, text2);
        */
    }
};
// @lc code=end
