/*
 * @lc app=leetcode id=1814 lang=cpp
 *
 * [1814] Count Nice Pairs in an Array
 */

// @lc code=start
class Solution {
   public:
    int countNicePairs(vector<int>& nums) {
        /* Approach:
            1. Unordered_Map -- T.C: O(N), S.C: O(N)
        */

        // Approach 1 -- Unordered_Map
        /* Observation:
            nums[i] + rev(nums[j]) == nums[j] + rev(nums[i]) can be rearranged to:
            nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
            Thus if we calculate x - rev(x) and store in map then we can check how many other y statifies this property
        */
        int ans = 0;
        int MOD = 1e9 + 7;
        int n = nums.size();
        unordered_map<int, int> mp;

        int rev_x;
        int dup_x;
        int diff;
        for (int x : nums) {  // T.C: O(N)
            dup_x = x;
            rev_x = 0;
            while (x) {  // T.C: O(10) as elements can be at max : 1e9
                rev_x = rev_x * 10 + x % 10;
                x /= 10;
            }
            // nums[i] - rev(nums[i])
            diff = dup_x - rev_x;
            /*
            if (mp.find(revDiff) != mp.end())
                ans = (ans + mp[diff]) % MOD;
            */
            ans = (ans + mp[diff]) % MOD;
            mp[diff]++;
        }
        return ans;
    }
};
// @lc code=end
