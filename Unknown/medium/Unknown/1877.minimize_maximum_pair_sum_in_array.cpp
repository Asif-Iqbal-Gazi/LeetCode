/*
 * @lc app=leetcode id=1877 lang=cpp
 *
 * [1877] Minimize Maximum Pair Sum in Array
 */

// @lc code=start
class Solution {
   public:
    int minPairSum(vector<int>& nums) {
        /* Approach:
            1. Sort -- T.C: O(n log n), S.C: O(1)
        */

        // Approach 1 -- Sorting
        /* Obervation:
            - Sort and pair the largest and smallest and so on
            - Can be proven by contradiction
        */

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = n - 1;
        int sum = 0;
        int ans = INT_MIN;
        while (i < j) {
            sum = nums[i++] + nums[j--];
            ans = max(ans, sum);
        }
        return ans;
    }
};
// @lc code=end
