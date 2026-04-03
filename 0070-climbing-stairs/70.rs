impl Solution {
    fn climb_stairs_helper(n: usize, dp: &mut Vec<i32>) -> i32 {
        if n <= 3 {
            dp[n] = n as i32;
            return dp[n];
        }
        if dp[n] != -1 {
            return dp[n];
        }
        dp[n] = Self::climb_stairs_helper(n - 1, dp)
              + Self::climb_stairs_helper(n - 2, dp);
        dp[n]
    }

    pub fn climb_stairs(n: i32) -> i32 {
        /*
         * Approach:
         * 1. Recursion                -- T.C: O(2^N), S.C: O(N) -- TLE
         * 2. Recursion + Memoization  -- T.C: O(N),   S.C: O(N)
         * 3. Bottom-Up DP (Tabular)   -- T.C: O(N),   S.C: O(N)
         * 4. Bottom-Up DP (Optimized) -- T.C: O(N),   S.C: O(1)
         *
         * Key Insight: climb_stairs(n) = climb_stairs(n-1) + climb_stairs(n-2)
         * This is identical to the Fibonacci sequence.
         */

        /* Approach 1 -- Recursion
        if n <= 3 { return n; }
        Self::climb_stairs(n - 1) + Self::climb_stairs(n - 2)
        */

        /* Approach 2 -- Recursion + Memoization
        let mut dp = vec![-1i32; (n + 1) as usize];
        Self::climb_stairs_helper(n as usize, &mut dp)
        */

        /* Approach 3 -- Bottom-Up DP
        if n <= 3 { return n; }
        let mut dp = vec![0i32; (n + 1) as usize];
        dp[1] = 1;
        dp[2] = 2;
        for i in 3..=(n as usize) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        dp[n as usize]
        */

        // Approach 4 -- Bottom-Up DP, Space Optimized
        if n <= 3 {
            return n;
        }
        let mut prev2prev = 1;
        let mut prev      = 2;
        for _ in 3..=n {
            let curr  = prev + prev2prev;
            prev2prev = prev;
            prev      = curr;
        }
        prev
    }
}
