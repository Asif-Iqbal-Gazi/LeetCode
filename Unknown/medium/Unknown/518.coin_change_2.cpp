class Solution
{
private:
    int solveTopDown(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        int n = coins.size();
        if (amount == 0)
            return 1;

        int &ans = dp[ind][amount];
        if (ans != -1)
            return ans;

        ans = 0;
        for (int i = ind; i < n; i++)
        {
            if (amount < coins[i])
                break;
            ans += solveTopDown(i, amount - coins[i], coins, dp);
        }
        return ans;
    }

public:
    int change(int amount, vector<int> &coins)
    {
        /* Approach:
            1. DP (Top Down) -- T.C: O(n * n * amount), S.C: O(n * amount)
            2. DP (Bottom UP) -- T.C: O(n * amount), S.C: O(amount)
        */

        /*
            DP State:
                dp(i) = No of combination to that make amount i, with given denomination
            DP Transition:
                dp(i) = sum(dp[i - coin[j]]), for all j
            Base Case:
                dp[0] = 1;
        */

        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];

        /* Approach 1
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        return solveTopDown(0, amount, coins, dp);
        */
    }
};