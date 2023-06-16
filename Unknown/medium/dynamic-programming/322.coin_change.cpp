/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution
{
public:
    /* Aproach 2
    int solveTopDown(int amount, vector<int> &coins, vector<int> &dp){
        // Base Case
        if(amount < 0)
            return 1e6;
        if(amount == 0)
            return 0;

        if(dp[amount] != -1) return dp[amount];

        int ans = 1e6;
        for(int i = 0; i < coins.size(); i++){
            if(coins[i] <= amount)
                ans = min(ans, 1 + solveTopDown(amount - coins[i], coins, dp));
        }
        return dp[amount] = ans;
    }
    */

    /* Approach 1
    int solveRec(int amount, vector<int> &coins){
        if(amount == 0)
            return amount == 0 ? 0 : 1e9;

        int ans = 1e6;
        for(int i = 0; i < coins.size(); i++){
            if(coins[i] <= amount)
                ans = min(ans, 1 + solveRec(amount - coins[i], coins));
        }
        return ans;
    }
    */

    int coinChange(vector<int> &coins, int amount)
    {
        /* Approach:
            1. Recursion -- T.C: Exponential, S.C: O(amount/min(coins))
            2. DP (Top Down) -- T.C: O(amount*n), S.C: O(amount)
            3. DP (Bottom Up) -- T.C: O(amount*n), S.C: O(amount)
            4. DP (Optimised Bottom Up) -- T.C: O(amount * n), S.C: O(amount)
        */

        // Approach 4
        int dp[amount + 1];
        dp[0] = 0;

        // Sort to skip checking
        sort(coins.begin(), coins.end());

        for (int i = 1; i <= amount; i++)
        {
            dp[i] = 1e6;
            for (int j = 0; j < coins.size(); j++)
            {
                if (coins[j] > i)
                    break; // Optimisation due to sorting
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }

        return dp[amount] >= 1e6 ? -1 : dp[amount];

        /* Approach 3
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++){
            dp[i] = 1e9;
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0)
                    dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
            }
        }

        return dp[amount] == 1e9 ? -1 : dp[amount];
        */

        /* Approach 2
        vector<int> dp(amount+1, -1);

        int ans = solveTopDown(amount, coins, dp);

        return ans >= 1e6 ? -1 : ans;
        */

        /* Approach 1
        if(!amount) return 0;

        int ans = solveRec(amount, coins);

        return ans >= 1e6 ? -1 : ans;
        */
    }
};
// @lc code=end
