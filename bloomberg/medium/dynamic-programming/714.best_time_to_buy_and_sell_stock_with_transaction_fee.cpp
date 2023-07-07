/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        /* Approach:
            1. DP (Bottom Up) -- T.C : O(n), S.C: O(n)
            2. DP (Space Optimised) -- T.C: O(n), S.C: O(1)
        */

        /*
        DP State:
            dp[i][0/1] = Max Profit on ith day with stock holding status
        DP Transition:
            dp[i][1] = Max (dp[i - 1][0] - prices[i] - fee, dp[i - 1][1]);
            dp[i][0] = Max (dp[i - 1][1] + prices[i], dp[i - 1][0]);
        Base Case:
            dp[0][0] = 0;
            dp[0][1] = - prices[0] - fee; <-- Not defined
        Final Answer:
            max(dp[n - 1][0], dp[n - 1][1])
        */

        // Approach 2
        int n = prices.size();
        // Base Cases
        int prevNoHolding = 0;
        int prevHolding = -prices[0] - fee;
        int currHolding = 0;
        int currNoHolding = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (j == 0)
                    currNoHolding = max(prevHolding + prices[i], prevNoHolding);
                else
                    currHolding = max(prevNoHolding - prices[i] - fee, prevHolding);
            }
            prevHolding = currHolding;
            prevNoHolding = currNoHolding;
        }

        return prevNoHolding;

        /* Approach 1
        int n = prices.size();
        int dp[n][2];
        // Base Cases
        dp[0][0] = 0;
        dp[0][1] = - prices[0] - fee;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 2; j++) {
                if(j == 0)
                    dp[i][j] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
                else
                    dp[i][j] = max(dp[i - 1][0] - prices[i] - fee, dp[i - 1][1]);
            }
        }

        return dp[n - 1][0];
        */
    }
};
// @lc code=end
