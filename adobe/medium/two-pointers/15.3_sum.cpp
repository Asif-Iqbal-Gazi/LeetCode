/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        /* Approach:
            1. Sort + Two Pointers -- T.C: O(N^2), S.C: O(1)
        */

        int sum = 0;
        int n = nums.size();
        vector<vector<int>> res;
        // Sort
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++)
        {
            // Remove duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                sum = nums[i] + nums[l] + nums[r];
                if (0 < sum)
                    r--;
                else if (0 > sum)
                    l++;
                else
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                // Remove left duplicate
                while (l < r && l > (i + 1) && nums[l] == nums[l - 1])
                    l++;
                // Remove right duplicatet
                while (l < r && r < (n - 1) && nums[r] == nums[r + 1])
                    r--;
            }
        }
        return res;
    }
};
// @lc code=end
