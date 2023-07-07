/*
 * @lc app=leetcode id=1413 lang=cpp
 *
 * [1413] Minimum Value to Get Positive Step by Step Sum
 */

// @lc code=start
class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        /* Approach:
            1. Prefix Sum -- T.C: O(n), S.C: O(1)
        */

        int n = nums.size();
        int prefixMin = nums[0];

        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i - 1];
            prefixMin = min(prefixMin, nums[i]);
        }

        return prefixMin < 1 ? 1 - prefixMin : 1;
    }
};
// @lc code=end
