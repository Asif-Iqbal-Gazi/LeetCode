/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
   private:
    /* Approach 1 -- Recursion + Memoization
    int dp[201][20001];
    bool solveRec(int ind, int subOneSum, vector<int> &nums) {
        // Base Case
        if (subOneSum == 0)
            return true;
        if (ind == nums.size() || subOneSum < 0)
            return false;

        int &ans = dp[ind][subOneSum];
        if (ans != -1)
            return ans;

        ans = 0;
        // Pick curr element for subset 1
        ans |= solveRec(ind + 1, subOneSum - nums[ind], nums);
        // Leave the element for subset 2
        ans |= solveRec(ind + 1, subOneSum, nums);
        return ans;
    }
    */
   public:
    bool canPartition(vector<int> &nums) {
        /* Approach:
            1. Recursion + Memoization -- T.C: O(n * m), S.C: O(n * m)
            2. DP (Bottom Up) -- T.C: O(n * m), S.C: O(n * m)
            3. DP (Bottom Up + Space Optimised) -- T.C: O(n * m), S.C: O(m)
        */

        // Approach 3 -- DP (Bottom Up + Space Optimised)
        int totalSum = 0;
        for (int x : nums)
            totalSum += x;
        // If totalSum is odd can not be partitioned into equal sum
        if (totalSum & 1)
            return false;

        int subsetSum = totalSum / 2;
        vector<bool> dp(subsetSum + 1, false);
        // Base Case
        dp[0] = true;

        for (int curr : nums) {
            for (int j = subsetSum; j >= curr; j--) {
                // Pick the element
                dp[j] = dp[j] || dp[j - curr];
            }
        }

        return dp[subsetSum];

        /* Approach 2 -- DP (Bottom Up)
        int totalSum = 0;
        for (int x : nums)
            totalSum += x;
        // If totalSum is odd can not be partitioned into equal sum
        if (totalSum & 1)
            return false;

        //
        //     DP State:
        //         dp[i][j] : Can we make sum j using first i elements
        //     State Transition:
        //         dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]]
        //     Base Case:
        //         dp[0][0] = true
        //     Final Answer:
        //         dp[n][totalSum / 2]
        //

        int n = nums.size();
        int m = totalSum / 2;
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));

        // Base Case
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                // Leave the element
                dp[i][j] = dp[i - 1][j];
                // Pick the element
                if (j - nums[i - 1] >= 0)
                    dp[i][j] |= dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[n][m];
        */

        /* Approach 1
        int totalSum = 0;
        for (int x : nums)
            totalSum += x;
        // If totalSum is odd can not be partitioned into equal sum
        if (totalSum & 1) return false;
        // memset dp array
        memset(dp, -1, sizeof(dp));
        return solveRec(0, totalSum / 2, nums);
        */
    }
};
// @lc code=end
