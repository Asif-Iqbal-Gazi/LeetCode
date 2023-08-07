/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        /* Approach:
            1. Bruteforce -- T.C: O(n^2), S.C: O(1)
            2. Sliding Window -- T.C: O(n), S.C: O(1)
        */

        // Approach 2 -- Sliding Window
        int ans = 0;
        int n = nums.size();

        int l = 0, r = 0;
        while (r < n) {
            if (nums[r] == 0)
                k--;
            // Note here are not decrementing the window size
            // Thus if (k < 0) instead of while (k < 0)
            if (k < 0) {
                k += 1 - nums[l];
                l++;
            }
            r++;
        }
        // In our approach we never contract the window size,
        // Thus r - l is fixed
        return r - l;

        /* Approach 1 -- Bruteforce
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int flipCount = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == 0) flipCount++;
                if (flipCount <= k) ans = max(ans, j - i + 1);
                else break;
            }
        }
        return ans;
        */
    }
};
// @lc code=end
