/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [2811] https://leetcode.com/problems/check-if-it-is-possible-to-split-array/description/
 */

// @lc code=start
class Solution {
   public:
    bool canSplitArray(vector<int>& nums, int m) {
        /* Approach:
            1. Linear Scan -- T.C: O(n), S.C: O(1)
                -- Prefix Sum & Sliding Window
                -- Baiscally, once your entire array sum is >= m, you can split it
                -- You can split from either end, so what matters is before last split, you have to have sum >= m
                   In other word, sum of two consecutive elements >= m, then you can split

        */

        int n = nums.size();
        if (m == 1 || n <= 2) return true;

        for (int i = 1; i < n; i++) {
            if (nums[i] + nums[i - 1] >= m) return true;
        }

        return false;
    }
};
// @lc code=end
