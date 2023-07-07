/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution
{
public:
    /* Approach 2
    int solveTopDown(int ind, int holding, int k, vector<int> &prices,
                     vector<vector<vector<int>>> &dp){
        if(ind == prices.size() || k == 0)
            return 0;

        if(dp[ind][k][holding] != -1)
            return dp[ind][k][holding];

        int doNothing = solveTopDown(ind + 1, holding, k, prices, dp);
        int doSomething = 0;
        // Choices
        if(!holding) // Buy
            doSomething = -prices[ind] + solveTopDown(ind + 1, 1, k, prices, dp);
        else // Sell
            doSomething = prices[ind] + solveTopDown(ind + 1, 0, k - 1, prices, dp);

        return dp[ind][k][holding] = max(doNothing, doSomething);
    }
    */

    /* Approach 1
    int solveRec(int ind, int holding, int k, vector<int> &prices){
        if(ind == prices.size() || k == 0)
            return 0;

        int ans = 0;
        // Choices
        if(!holding){
            // Not Buy
            ans = solveRec(ind + 1, 0, k, prices);
            // Buy
            ans = max(ans, -prices[ind] + solveRec(ind + 1, 1, k, prices));
        }
        else{
            // Not Sell
            ans = solveRec(ind + 1, 1, k, prices);
            // Sell
            ans = max(ans, prices[ind] + solveRec(ind + 1, 0, k - 1, prices));
        }

        return ans;
    }
    */

    int maxProfit(int k, vector<int> &prices)
    {
        /* Approach:
            1. Recursion -- T.C: Exponential
            2. DP (Top Down) -- T.C: O(n*k*2), S.C: O(n*k*2)
            3. Dp (Bottom Up) -- T.C: O(n*k*2), S.C: O(n*k*2)
        */

        // Approach 3
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int transactionRemaining = 1; transactionRemaining <= k; transactionRemaining++)
            {
                for (int holding = 0; holding < 2; holding++)
                {
                    int doNothing = dp[ind + 1][transactionRemaining][holding];
                    int doSomething = 0;
                    // Choices
                    if (!holding) // Buy
                        doSomething = -prices[ind] + dp[ind + 1][transactionRemaining][1];
                    else // Sell
                        doSomething = prices[ind] + dp[ind + 1][transactionRemaining - 1][0];

                    dp[ind][transactionRemaining][holding] = max(doNothing, doSomething);
                }
            }
        }
        return dp[0][k][0];

        /* Approach 2
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));

        return solveTopDown(0, 0, k, prices, dp);
        */

        /* Approach 1
        return solveRec(0, 0, k, prices);
        */
    }
};
// @lc code=end
