/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
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
private:
    int findFib(int n, vector<int> &dp)
    {
        if (n <= 1)
            return dp[n] = n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = findFib(n - 1, dp) + findFib(n - 2, dp);
    }

public:
    int fib(int n)
    {
        /* Approach:
            1. Using Simple Recursion -- T.C: O(2^N), S.C: O(N) -- Gets TLE
            2. Recursion + Memoization -- T.C: O(N), S.C: O(N)
            3. DP (Bottom Up) -- T.C: O(N), S.C: O(N)
            4. DP (Bottom Up) + Space Optimization -- T.C: O(N), S.C: O(1)
        */

        /* Approach 1
        if (n <= 1)
            return n;
        return fib(n - 1) + fib(n - 2);
        */

        /* Approach 2
        vector<int> dp(n + 1, -1);
        return findFib(n, dp);
        */

        /* Approach 3
        if (n <= 1)
            return n;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
        */

        // Approach 4
        if (n <= 1)
            return n;
        int prev = 1;
        int prev2prev = 0;
        for (int i = 2; i <= n; i++)
        {
            int curr = prev + prev2prev;
            prev2prev = prev;
            prev = curr;
        }
        return prev;
    }
};
// @lc code=end
