/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
class Solution {
   private:
    int numSubarraysWithSumAtleastEqualK(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int l = 0, r = 0;

        int runningSum = 0;
        while (r < n) {
            runningSum += nums[r];
            r++;

            while (l < r && runningSum >= k) {
                ans += n - r + 1;
                runningSum -= nums[l];
                l++;
            }
        }
        return ans;
    }

   public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        /* Approach:
            1. BruteForce -- T.C: O(n^2), S.C: O(1)
            2. Sliding Window + Prefix Sum -- T.C: O(n), S.C: O(n)
            3. Sliding Window (Atleast Sum) -- T.C: O(n), S.C: O(1)
                -- Here, we are finding the number of subarrays with sum >= goal
                -- Then, we are finding the number of subarrays with sum >= goal + 1
                -- Then, we are subtracting the two to get the number of subarrays with sum == goal
        */

        // Approach 3 -- Sliding Window (Atleast Sum)
        return numSubarraysWithSumAtleastEqualK(nums, goal) - numSubarraysWithSumAtleastEqualK(nums, goal + 1);

        /* Approach 2 -- Sliding Window
        int ans = 0;
        int n = nums.size();
        int l = 0, r = 0;

        int runningSum = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[0]++;
        while (r < n) {
            runningSum += nums[r];
            r++;

            if (prefixSum.count(runningSum - goal))
                ans += prefixSum[runningSum - goal];
            prefixSum[runningSum]++;
        }
        return ans;
        */

        /* Approach 1 -- BruteForce
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n && sum <= goal; j++) {
                sum += nums[j];
                if (sum == goal)
                    ans++;
            }
        }
        return ans;
        */
    }
};
// @lc code=end
