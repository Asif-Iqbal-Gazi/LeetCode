/*
 * @lc app=leetcode id=1473 lang=cpp
 *
 * [1473] Paint House III
 */

// @lc code=start
class Solution
{
public:
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
    {
        /* Approach:
            1. DP (Bottom Up) -- T.C: O(m * T * n^2), S.C: O(m * T * n)
            2. DP (Bottom Up + Space Optimised) -- T.C: O(m * T * n^2), S.C: O(T * n)
        */

        /*
        DP State:
            dp[i][k][j] : Minimum cost of painting first i houses s.t there are k neighborhoods ans ith house is painted with color j

        DP Transition:
            if(houses[i])
                dp[i][k][j] = min(dp[i - 1][k - 1][l], dp[i - 1][k][j]);
                              Here, j = houses[i]; l : all color - 'j'
            else
                dp[i][k][j] = min(dp[i - 1][k - 1][l], dp[i - 1][k][j]) + cost[i][j]
                              For all color - 'j'

        Base Condition:
                dp[0][1][color] = 0; if houses[0] == color,
                dp[0][1][color] = cost[0][color - 1]; if house is not painted

        */

        // Approach 2
        const int MAX_COST = 1e6 + 1;
        vector<vector<int>> prev(target + 1, vector<int>(n, MAX_COST));

        // Base Case
        for (int color = 1; color <= n; color++)
        {
            if (houses[0] == color)
                prev[1][color - 1] = 0; // House is already painted with same color, no cost
            else if (!houses[0])
                prev[1][color - 1] = cost[0][color - 1]; // House is not painted
        }

        // DP Logic
        for (int hIndex = 1; hIndex < m; hIndex++)
        {
            vector<vector<int>> curr(target + 1, vector<int>(n, MAX_COST));
            for (int nei = 1; nei <= min(target, hIndex + 1); nei++)
            {
                for (int color = 1; color <= n; color++)
                {
                    // House is already painted, but curr color is not same
                    if (houses[hIndex] && houses[hIndex] != color)
                        continue;

                    int minPrevCost = MAX_COST;
                    for (int prevColor = 1; prevColor <= n; prevColor++)
                    {
                        if (prevColor == color)
                            minPrevCost = min(minPrevCost, prev[nei][color - 1]);
                        else
                            minPrevCost = min(minPrevCost, prev[nei - 1][prevColor - 1]);
                    }
                    int costToPaint = houses[hIndex] ? 0 : cost[hIndex][color - 1];
                    curr[nei][color - 1] = minPrevCost + costToPaint;
                }
            }
            prev = curr;
        }

        // Answer
        int minCost = MAX_COST;
        for (int i = 0; i < n; i++)
        {
            minCost = min(minCost, prev[target][i]);
        }

        return minCost == MAX_COST ? -1 : minCost;

        /* Approach 1
        const int MAX_COST = 1e6 + 1;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(target + 1, vector<int>(n, MAX_COST)));

        // Base Case
        for(int color = 1; color <= n; color++) {
            if(houses[0] == color)
                dp[0][1][color - 1] = 0;    // House is already painted with same color, no cost
            else if(!houses[0])
                dp[0][1][color - 1] = cost[0][color - 1]; // House is not painted
        }

        // DP Logic
        for(int hIndex = 1; hIndex < m; hIndex++) {
            for(int nei = 1; nei <= min(target, hIndex + 1); nei++) {
                for(int color = 1; color <= n; color++) {
                    // House is already painted, but curr color is not same
                    if(houses[hIndex] && houses[hIndex] != color)
                        continue;

                    int minPrevCost = MAX_COST;
                    for(int prevColor = 1; prevColor <= n; prevColor++) {
                        if(prevColor == color)
                            minPrevCost = min(minPrevCost, dp[hIndex - 1][nei][color - 1]);
                        else
                            minPrevCost = min(minPrevCost, dp[hIndex - 1][nei - 1][prevColor - 1]);
                    }
                    int costToPaint = houses[hIndex] ? 0 : cost[hIndex][color - 1];
                    dp[hIndex][nei][color - 1] = minPrevCost + costToPaint;
                }
            }
        }

        // Answer
        int minCost = MAX_COST;
        for(int i = 0; i < n; i++) {
            minCost = min(minCost, dp[m - 1][target][i]);
        }

        return minCost == MAX_COST ? -1 : minCost;
        */
    }
};
// @lc code=end
