/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        /* Approach:
            1. Naive Method -- T.C: O(N), S.C: O(1)
            2. XOR Method -- T.C: O(N), S.C: O(1)
            3. Binray Search -- T.C: O(log(N)), S.C: O(1)
        */

        /* Approach 1
        // Edge Cases
        if (nums.size() == 1)
            return nums[0];

        int n = nums.size();
        for (int i = 1; i < n; i += 2)
        {
            if (nums[i] != nums[i - 1])
                return nums[i - 1];
        }
        return nums[n - 1];
        */

        /* Approach 2
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
            ans ^= nums[i];

        return ans;
        */

        // Approach 3
        int n = nums.size();

        int l = 0, h = n - 2;

        while (l <= h)
        {
            int m = l + (h - l) / 2;
            if (nums[m] == nums[m ^ 1])
                l = m + 1;
            else
                h = m - 1;
        }
        return nums[l];
    }
};
// @lc code=end
