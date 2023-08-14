/*
    2817. Minimum Absolute Difference Between Elements With Constraint
    minimum-absolute-difference-between-elements-with-constraint
*/

class Solution {
   public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        /* Approach:
            1. Using Multiset -- T.C: O(n log n), S.C: O(n)
        */

        int n = nums.size();
        int i = 0;
        multiset<int> ms;
        for (i = x; i < n; i++)
            ms.insert(nums[i]);

        int ans = 1e9;

        for (i = 0; i < n; i++) {
            if (i >= x) ms.insert(nums[i - x]);
            // auto it = ms.find(nums[i]); <-- This doesn't do lower_bound internally
            auto it = ms.lower_bound(nums[i]);
            if (it != ms.end()) {
                ans = min(ans, abs(nums[i] - *it));
            }
            if (i + x < n) ms.erase(ms.find(nums[i + x]));
        }

        return ans;
    }
};