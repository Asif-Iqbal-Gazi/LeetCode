/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        /* Approach:
            1. Bruteforce -- T.C: O(N), S.C: O(1)
            2. Binary Search -- T.C: O(log(N)), S.C: O(1)
        */

        /* Approach 1
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
                return i;
        }
        return -1;
        */

        // Approach 2
        int n = nums.size();
        int l = 0;
        int h = n - 1;

        while (l <= h)
        {
            int m = l + (h - l) / 2;
            if (nums[m] == target)
                return m;
            if (nums[m] >= nums[l])
            {
                if (target >= nums[l] && target <= nums[m])
                    h = m - 1;
                else
                    l = m + 1;
            }
            else
            {
                if (target <= nums[h] && target >= nums[m])
                    l = m + 1;
                else
                    h = m - 1;
            }
        }
        return -1;
    }
};
// @lc code=end
