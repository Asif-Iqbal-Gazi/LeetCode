/*
 * @lc app=leetcode id=1918 lang=cpp
 *
 * [1918] Kth Smallest Subarray Sum
 */

// @lc code=start
class Solution {
   private:
    int countSubArrayLessEqual(vector<int> &nums, int target) {
        int n = nums.size();
        int count = 0;
        int l = 0, r = 0, runningSum = 0;
        for (r = 0; r < n; r++) {  // T.C: O(N)
            runningSum += nums[r];
            while (runningSum > target) {
                runningSum -= nums[l++];
            }
            count += (r - l + 1);
        }
        return count;
    }

   public:
    int kthSmallestSubarraySum(vector<int> &nums, int k) {
        /* Approach:
            1. Binary Search on Answer -- T.C: O(N log Sum), S.C: O(1)
        */

        int l = 0;
        int r = 1e9;
        /* Binary Search Invariance
            0 0 0 0 1 1 1 1 1 1
            predicate(r) >= k always true
            predicate(l) >= k always false
        */
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (countSubArrayLessEqual(nums, m) >= k)
                r = m;
            else
                l = m;
        }
        return r;
    }
};
// @lc code=end
