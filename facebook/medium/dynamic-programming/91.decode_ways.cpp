/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution
{
public:
    int numDecodings(string s)
    {
        /* Approach:
            1. DP (Bottom Up) -- T.C: O(n), S.C: O(1)
        */

        /*
            DP State:
                dp[i] = No of ways to decode s[0:i]

            DP Transition:
                dp[i] = if(s[i] == '0' && s[i-1:i] in map) dp[i - 2]
                        else{
                            dp[i - 1]
                            + if(s[i-1: i] in map) dp[i - 2]
                        }
            Base Case:
                dp[0] = 1 provided s[0] != '0'

        */

        // Edge Case
        if (s[0] == '0')
            return 0;

        int dp[3];
        int n = s.size();

        dp[0] = s[0] != '0' ? 1 : 0;
        dp[1] = s[1] != '0' ? 1 : 0;
        int twoDigit = s[0] - '0';
        twoDigit *= 10;
        twoDigit += s[1] - '0';
        if (twoDigit <= 26)
            dp[1]++;

        for (int i = 2; i < n; i++)
        {
            dp[2] = 0;
            twoDigit = s[i - 1] - '0';
            if (twoDigit != 0)
            {
                twoDigit *= 10;
                twoDigit += (s[i] - '0');
            }

            if (twoDigit > 0 && twoDigit <= 26)
            {
                dp[2] += dp[0];
            }
            if (s[i] != '0')
                dp[2] += dp[1];
            dp[0] = dp[1];
            dp[1] = dp[2];
        }

        return (n == 1) ? dp[0] : dp[1];
    }
};
// @lc code=end
