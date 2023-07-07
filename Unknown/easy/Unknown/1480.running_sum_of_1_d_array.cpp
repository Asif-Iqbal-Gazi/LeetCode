/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        /* Approach:
            1. Linear Iteration -- T.C: O(n), S.C: O(1)
        */

        int n = nums.size();

        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i - 1];
        }

        return nums;
    }
};
// @lc code=end
