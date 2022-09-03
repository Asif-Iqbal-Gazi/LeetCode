/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        /* Approach:
            1. Optimal Method -- T.C: O(NlogN), S.C: O(1)
        */

        if (intervals.size() == 1)
            return intervals;
        int n = intervals.size();
        // Sort intervals
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans = {intervals[0]};
        for (int i = 1; i < n; i++)
        {
            int ansSize = ans.size() - 1;
            if (intervals[i][0] <= ans[ansSize][1])
            {
                ans[ansSize][1] = max(intervals[i][1], ans[ansSize][1]);
            }
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};
// @lc code=end
