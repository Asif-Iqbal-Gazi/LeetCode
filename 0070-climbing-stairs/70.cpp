class Solution {
  public:
    int climbStairs(int n) {
        /*
         * Approach:
         * 1. Recursion                -- T.C: O(2^N), S.C: O(N) -- TLE
         * 2. Recursion + Memoization  -- T.C: O(N),   S.C: O(N)
         * 3. Bottom-Up DP (Tabular)   -- T.C: O(N),   S.C: O(N)
         * 4. Bottom-Up DP (Optimized) -- T.C: O(N),   S.C: O(1)
         *
         * Key Insight: climbStairs(n) = climbStairs(n-1) + climbStairs(n-2)
         * This is identical to the Fibonacci sequence.
         */

        /* Approach 1 -- Recursion
        if (n <= 3)
            return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
        */

        /* Approach 2 -- Recursion + Memoization
        vector<int> dp(n + 1, -1);
        return climbStairs(n, dp);
        */

        /* Approach 3 -- Bottom-Up DP
        if (n <= 3)
            return n;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
        */

        // Approach 4 -- Bottom-Up DP, Space Optimized
        if (n <= 3)
            return n;
        int prev2prev = 1;
        int prev      = 2;
        for (int i = 3; i <= n; i++) {
            int curr  = prev + prev2prev;
            prev2prev = prev;
            prev      = curr;
        }
        return prev;
    }

  private:
    int climbStairs(int n, vector<int>& dp) {
        if (n <= 3)
            return dp[n] = n;
        if (dp[n] == -1)
            dp[n] = climbStairs(n - 1, dp) + climbStairs(n - 2, dp);
        return dp[n];
    }
};
