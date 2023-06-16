/*
 * @lc app=leetcode id=1335 lang=cpp
 *
 * [1335] Minimum Difficulty of a Job Schedule
 */

// @lc code=start
class Solution
{
private:
    // Approach 2 -- DP (Top Down)
    int solveTopDown(int dayRemains, int jobId, vector<int> &jobDifficulty, vector<vector<int>> &dp)
    {
        if (dp[dayRemains][jobId] != -1)
            return dp[dayRemains][jobId];

        int ans = INT_MAX;
        int maxDifficulty = INT_MIN;
        int jobCount = jobDifficulty.size();
        // Base Case
        if (dayRemains == 1)
        {
            maxDifficulty = jobDifficulty[jobId];
            while (++jobId < jobCount)
            {
                if (jobDifficulty[jobId] > maxDifficulty)
                    maxDifficulty = jobDifficulty[jobId];
            }
            return maxDifficulty;
        }

        for (int currJobId = jobId; currJobId <= jobCount - dayRemains; currJobId++)
        {
            if (maxDifficulty < jobDifficulty[currJobId])
                maxDifficulty = jobDifficulty[currJobId];
            ans = min(ans, maxDifficulty + solveTopDown(dayRemains - 1, currJobId + 1, jobDifficulty, dp));
        }
        return dp[dayRemains][jobId] = ans;
    }

    /* Approach 1 -- Recursion
    int solveRec(int dayRemains, int jobId, vector<int> &jobDifficulty)
    {
        int ans = INT_MAX;
        int maxDifficulty = INT_MIN;
        int jobCount = jobDifficulty.size();
        // Base Case
        if (dayRemains == 1)
        {
            maxDifficulty = jobDifficulty[jobId];
            while (++jobId < jobCount)
            {
                if (jobDifficulty[jobId] > maxDifficulty)
                    maxDifficulty = jobDifficulty[jobId];
            }
            return maxDifficulty;
        }

        for (int currJobId = jobId; currJobId <= jobCount - dayRemains; currJobId++)
        {
            if (maxDifficulty < jobDifficulty[currJobId])
                maxDifficulty = jobDifficulty[currJobId];
            ans = min(ans, maxDifficulty + solveRec(dayRemains - 1, currJobId + 1, jobDifficulty));
        }
        return ans;
    }
    */

public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        /* Approach:
            1. Recursion -- T.C: O((n - 1) C (d - 1)), S.C: O(d)
            2. DP (Top Down) -- T.C: O(n^2 * d), S.C: O(n * d)
            3. DP (Bottom Up) -- T.C: O(n^2 * d), S.C: O(n * d)

        */

        // Approach 3 -- DP (Bottom Up)
        // TO-DO

        // Approach 2 -- DP (Top Down)
        int n = jobDifficulty.size();
        // Edge Case
        if (n < d)
            return -1;
        vector<vector<int>> dp(d + 1, vector<int>(n, -1));
        return solveTopDown(d, 0, jobDifficulty, dp);

        /* Approach 1 -- Recursion
        int n = jobDifficulty.size();
        // Edge Case
        if (n < d)
            return -1;
        return solveRec(d, 0, jobDifficulty);
        */
    }
};
// @lc code=end
