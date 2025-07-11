/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        /* Approach:
            1. Two Pointers + Sliding Window -- T.C: O(n), S.C: O(1)
        */

        int l = 0;
        int r = 0;
        int n = nums.size();

        while (r < n)
        {
            if (nums[r] == 0)
                k--;

            if (k < 0)
            {
                k += 1 - nums[l];
                l++;
            }
            r++;
        }
        return r - l;
    }
};
// @lc code=end
