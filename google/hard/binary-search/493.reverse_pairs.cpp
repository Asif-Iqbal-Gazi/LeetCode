/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        /* Approach:
            1. Bruteforce -- T.C: O(N^2), S.C: O(1) -- Gets TLE
        */

        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long first = nums[i];
                long second = nums[j];
                second *= 2;
                if (first > second)
                    count++;
            }
        }
        return count;
    }
};
// @lc code=end
