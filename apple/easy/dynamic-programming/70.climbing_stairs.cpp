/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int climbStairs(int n)
    {
        /* Approach:
            1. Recursion -- T.C: O(2^N), S.C: O(N) -- Gets TLE
            2. Recursion with Memoization -- T.C: O(N), S.C: O(N)
            3. Tabular DP -- T.C: O(N), S.C: O(N)
            4. Tabular DP -- T.C: O(N), S.C: O(1)
        */

        /* Approach 1 -- Recursion
        // Base Cases
        if (n <= 3)
            return n;

        int leftRecursion = climbStairs(n - 1);
        int rightRecursion = climbStairs(n - 2);
        return leftRecursion + rightRecursion;
        */

        /* Approach 2 -- Recursion + Memoization
        vector<int> dp(n + 1, -1);
        return climbStairs(n, dp);
        */

        /* Approach 3 -- Bottom Up
        // Edge Case
        if (n <= 3)
            return n;
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
        */

        // Approach 4
        // Edge Case
        if (n <= 3)
            return n;
        int prev = 2;
        int pre_prev = 1;
        for (int i = 3; i <= n; i++)
        {
            int curr = prev + pre_prev;
            pre_prev = prev;
            prev = curr;
        }
        return prev;
    }

private:
    int climbStairs(int n, vector<int> &dp)
    {
        if (n <= 3)
        {
            dp[n] = n;
            return dp[n];
        }
        if (dp[n] == -1)
            dp[n] = climbStairs(n - 1, dp) + climbStairs(n - 2, dp);
        return dp[n];
    }
};
// @lc code=end
