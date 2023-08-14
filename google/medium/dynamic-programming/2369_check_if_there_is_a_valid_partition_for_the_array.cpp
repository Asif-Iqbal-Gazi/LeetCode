/*
 * @lc app=leetcode id=2369 lang=cpp
 *
 * [2369] Check if There is a Valid Partition For The Array
 */

// @lc code=start
class Solution {
   private:
    /* Approach 1 -- Recursion + Memoization
    int N;
    vector<int> dp;
    bool solveDP(int i, vector<int>& nums) {
        if (i > N)
            return false;
        if (i == N)
            return true;

        if (dp[i] != -1)
            return dp[i];

        // Case 1 -- Exact two equal
        bool op1 = (i + 1 < N && nums[i] == nums[i + 1]) && solveDP(i + 2, nums);

        // Case 2 -- Exact three equal
        bool op2 = (i + 2 < N && nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]) && solveDP(i + 3, nums);

        // Case 3 -- Three Consecutive
        bool op3 = (i + 2 < N && nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2]) && solveDP(i + 3, nums);

        return dp[i] = op1 || op2 || op3;
    }
    */
   public:
    bool validPartition(vector<int>& nums) {
        /* Approach:
            1. Recursion + Memoization -- T.C: O(N), S.C: O(N)
            2. DP (Bottom Up) -- T.C: O(N), S.C: O(N)
            3. DP (Bottom Up + Space Optimization) -- T.C: O(N), S.C: O(1)
        */

        // Approach 3 -- DP (Bottom Up + Space Optimization)
        int n = nums.size();
        if (n == 2) return nums[0] == nums[1];
        bool dp[4] = {false};
        // Arr   1 2 3 4 5 6 7
        // dp            T F F T  (0 0 1) --> (1 0 0)
        // dp          F T F F    (1 0 0) --> (0 1 0)
        // dp        F F T F
        // dp      F F F T

        dp[3] = true;
        dp[2] = false;
        dp[1] = nums[n - 2] == nums[n - 1];

        for (int i = n - 3; i >= 0; i--) {
            // Case 1 -- Exact 2 equal
            dp[0] |= !(nums[i] ^ nums[i + 1]) && dp[2];
            // Case 2 -- Exact 3 equal
            dp[0] |= !(nums[i] ^ nums[i + 1]) && !(nums[i + 1] ^ nums[i + 2]) && dp[3];
            // Case 3 -- Exact 3 Consecutive
            dp[0] |= (nums[i] + 1 == nums[i + 1]) && (nums[i + 1] + 1 == nums[i + 2]) && dp[3];
            dp[3] = dp[2];
            dp[2] = dp[1];
            dp[1] = dp[0];
            dp[0] = false;
        }

        return dp[1];

        /* Approach 2 -- DP (Bottom Up)
        int n = nums.size();
        bool dp[n + 1];
        memset(dp, 0, sizeof(dp));
        // Base Cases
        dp[n] = true;
        dp[n - 1] = false;
        dp[n - 2] = nums[n - 2] == nums[n - 1];

        // DP State:
        //     dp[i] : if s[i:] can have a valid partition
        // DP Transition:
        //     dp[i] = s[i:j) statisfies constraints and dp[j] == true
        //             range[i:j] must be equal to 2 or 3
        // DP Base Case:
        //     dp[N] = true
        //     dp[N - 1] = false
        // Final Answer:
        //     dp[0]

        for (int i = n - 3; i >= 0; i--) {
            // Case 1 -- Exact 2 equal
            dp[i] |= !(nums[i] ^ nums[i + 1]) && dp[i + 2];
            // Case 2 -- Exact 3 equal
            dp[i] |= (nums[i] == nums[i + 1]) && (nums[i + 1] == nums[i + 2]) && dp[i + 3];
            // Case 3 -- Exact 3 Consecutive
            dp[i] |= (nums[i] + 1 == nums[i + 1]) && (nums[i + 1] + 1 == nums[i + 2]) && dp[i + 3];
        }

        return dp[0];
        */

        /* Approach 1 -- Recursion + Memoization
        N = nums.size();
        dp.assign(N, -1);
        return solveDP(0, nums);
        */
    }
};
// @lc code=end