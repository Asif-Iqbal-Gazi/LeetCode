/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start
class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        /* Approach:
            Get the cumulative gain for all points, pick the max gain
            1. Prefix Sum -- T.C: O(n), S.C: O(1)
        */

        int n = gain.size();

        int curr = 0; // prefix[i]
        int prev = 0; // prefix[i - 1]

        int ans = prev;
        for (int i = 0; i < n; i++)
        {
            curr = prev + gain[i];
            ans = max(ans, curr);
            prev = curr;
        }

        return ans;
    }
};
// @lc code=end
