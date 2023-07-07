/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        /* Approach:
            1. Sliding Window -- T.C: O(n), S.C: O(1)
        */

        int l = 0;
        int r = 0;
        int n = nums.size();

        int count = 0;

        while (r < n)
        {
            if (nums[r] == 0)
                count++;

            if (count > 1)
            {
                count -= 1 - nums[l];
                l++;
            }
            r++;
        }

        // Minus 1 because, we delete one element
        return r - l - 1;
    }
};
// @lc code=end
