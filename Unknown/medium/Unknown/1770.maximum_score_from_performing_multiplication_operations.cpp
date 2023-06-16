/*
 * @lc app=leetcode id=1770 lang=cpp
 *
 * [1770] Maximum Score from Performing Multiplication Operations
 */

// @lc code=start
class Solution
{
private:
    /* Approach 1, 2, 3
    int N, M;
    vector<vector<int>> dp;
    */

public:
    /* Approach 2 -- Top Down
    int solveTopDown(int l, int op, vector<int> &nums, vector<int> &multipliers)
    {
        // Base case
        if (op == M)
            return 0;

        int &ans = dp[l][op];

        if (ans != -1)
            return ans;

        int mul = multipliers[op];
        int r = (N - 1) - (op - l);
        // Choice 1 -- Left
        int choiceLeft = mul * nums[l] + solveTopDown(l + 1, op + 1, nums, multipliers);
        // Choice 2 -- Right
        int choiceRight = mul * nums[r] + solveTopDown(l, op + 1, nums, multipliers);

        ans = max(choiceLeft, choiceRight);

        return ans;
    }
    */

    /* Approach 1 -- Recursion
    int solveRec(int l, int op, vector<int> &nums, vector<int> &multipliers)
    {
        // Base case
        if (op == M)
            return 0;

        int mul = multipliers[op];
        int r = (N - 1) - (op - l);
        // Choice 1 -- Left
        int choiceLeft = mul * nums[l] + solveRec(l + 1, op + 1, nums, multipliers);
        // Choice 2 -- Right
        int choiceRight = mul * nums[r] + solveRec(l, op + 1, nums, multipliers);

        return max(choiceLeft, choiceRight);
    }
    */

    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        /* Approach:
            1. Recursion -- T.C: O(2^m), S.C: O(m)
            2. DP (Top Down) -- T.C: O(m^2), S.C: O(m^2)
            3. DP (Bottom Up) -- T.C: O(m^2), S.C: O(m^2)
            4. DP (Space Optimized) -- T.C: O(m^2), S.C: O(m)
        */

        // Approach 4 -- DP (Space Optimised)
        int n = nums.size();
        int m = multipliers.size();

        vector<int> dp(m + 1, 0);

        for (int op = m - 1; op >= 0; op--)
        {
            for (int l = 0; l <= op; l++)
            {
                dp[l] = max(multipliers[op] * nums[l] + dp[l + 1],
                            multipliers[op] * nums[n - 1 - (op - l)] + dp[l]);
            }
        }

        return dp[0];

        /* Approach 3 -- DP (Bottom-Up)
        N = nums.size();
        M = multipliers.size();
        dp.assign(M + 1, vector<int>(M + 1, 0));

        for (int op = M - 1; op >= 0; op--)
        {
            int mul = multipliers[op];
            for (int l = 0; l <= op; l++)
            {
                dp[l][op] = max(mul * nums[l] + dp[l + 1][op + 1],
                                mul * nums[N - 1 - (op - l)] + dp[l][op + 1]);
            }
        }

        return dp[0][0];
        */

        /* Approach 2 -- DP (Top-Down)
        N = nums.size();
        M = multipliers.size();
        dp.assign(M + 1, vector<int>(M + 1, -1));
        return solveTopDown(0, 0, nums, multipliers);
        */

        /* Approach 1 -- Recursion
        N = nums.size();
        M = multipliers.size();
        return solveRec(0, 0, nums, multipliers);
        */
    }
};
// @lc code=end
