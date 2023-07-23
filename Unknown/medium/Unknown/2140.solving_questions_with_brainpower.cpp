/*
 * @lc app=leetcode id=2140 lang=cpp
 *
 * [2140] Solving Questions With Brainpower
 */

// @lc code=start
class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        /* Approach:
            1. DP (Bottom Up) -- T.C: O(n), S.C: O(n)
        */

        /*
            DP State:
                dp[i] : Maximum Score that can be achieved from making decision on questions[i:n]

            DP Transition:
                dp[i] = max(questions[0] + dp[i + questions[1] + 1], dp[i + 1])

            Base Case:
                dp[n] = 0;
        */

        int n = questions.size();

        cout << n << "\n";

        long long dp[n + 1];
        memset(dp, 0, sizeof(dp));
        // Base Case
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            long long skip = dp[i + 1];
            long long take = (1LL * questions[i][0] + dp[min(n, i + 1 + questions[i][1])]);
            dp[i] = max(skip, take);
        }

        return dp[0];
    }
};
// @lc code=end
