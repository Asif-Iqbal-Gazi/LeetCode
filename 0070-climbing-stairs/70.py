class Solution:
    def climbStairs(self, n: int) -> int:
        """
        Approach:
        1. Recursion                -- T.C: O(2^N), S.C: O(N) -- TLE
        2. Recursion + Memoization  -- T.C: O(N),   S.C: O(N)
        3. Bottom-Up DP (Tabular)   -- T.C: O(N),   S.C: O(N)
        4. Bottom-Up DP (Optimized) -- T.C: O(N),   S.C: O(1)

        Key Insight: climbStairs(n) = climbStairs(n-1) + climbStairs(n-2)
        This is identical to the Fibonacci sequence.
        """

        # Approach 1 -- Recursion
        # if n <= 3:
        #     return n
        # return self.climbStairs(n - 1) + self.climbStairs(n - 2)

        # Approach 2 -- Recursion + Memoization
        # from functools import lru_cache
        # @lru_cache(maxsize=None)
        # def helper(n):
        #     if n <= 3:
        #         return n
        #     return helper(n - 1) + helper(n - 2)
        # return helper(n)

        # Approach 3 -- Bottom-Up DP
        # if n <= 3:
        #     return n
        # dp = [0] * (n + 1)
        # dp[1] = 1
        # dp[2] = 2
        # for i in range(3, n + 1):
        #     dp[i] = dp[i - 1] + dp[i - 2]
        # return dp[n]

        # Approach 4 -- Bottom-Up DP, Space Optimized
        if n <= 3:
            return n
        prev2prev = 1
        prev = 2
        for i in range(3, n + 1):
            curr = prev + prev2prev
            prev2prev = prev
            prev = curr
        return prev
