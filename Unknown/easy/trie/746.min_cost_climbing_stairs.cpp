/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        /* Approach:
            1. DP (Bottom up) -- T.C: O(n), S.C: O(n)
            2. DP (Space Optimised) -- T.C: O(n), S.C: O(1)
        */

        /*
            DP State:
                dp[i] : Minimum cost to reach floor i
            DP Transistion:
                dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]
            Final Problem:
                dp[n-1]
            Base Case:
                dp[0] = 0;
                dp[1] = 0;
        */

        int n = cost.size();
        int dp[3];
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++)
        {
            dp[2] = min(dp[1] + cost[i - 1], dp[0] + cost[i - 2]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }

        return dp[2];
    }
};
// @lc code=end
