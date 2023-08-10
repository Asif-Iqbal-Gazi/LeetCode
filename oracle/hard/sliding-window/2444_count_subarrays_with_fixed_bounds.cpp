/*
 * @lc app=leetcode id=2444 lang=cpp
 *
 * [2444] Count Subarrays With Fixed Bounds
 */

// @lc code=start
class Solution {
   public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        /* Approach:
            1. Sliding Window + DP (Using multiset) -- T.C: O(nlogn), S.C: O(n)
            2. Sliding Window (3 Pointers) -- T.C: O(n), S.C: O(1)
                -- Credit @lee215
        */

        // Approach 2 -- Sliding Window (3 Pointers)
        long long int res = 0;
        int bad_i = -1, minK_i = -1, maxK_i = -1, n = nums.size();

        for (int j = 0; j < n; j++) {
            /* Explanation:
                -- If we have a valid window ending at j, and we know the last encountered bad index
                    bad_i : Index of the element < minK or > maxK
                -- Then there will be (bad - min(maxK_i, minK_i)) no of valid window
                    Note: Here bad < min(maxK_i, minK_i)
                -- Now, we can just do a linear scan keep track of last found bad_i, maxK_i, minK_i
            */
            if (nums[j] < minK || nums[j] > maxK) bad_i = j;
            if (nums[j] == maxK) maxK_i = j;
            if (nums[j] == minK) minK_i = j;
            res += max(0, min(maxK_i, minK_i) - bad_i);
            /* Starting of valid Window
            int start = min(maxK_i, minK_i);
            if (start > bad_i)
                res += start - bad_i;
            */
        }
        return res;

        /* Approach 1 -- Sliding Window + DP
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[n - 1] = (nums[n - 1] >= minK && nums[n - 1] <= maxK);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] >= minK && nums[i] <= maxK)
                dp[i] = 1 + dp[i + 1];
        }

        multiset<int> ms;
        long long int ans = 0;
        int left = 0, right = 0;

        for (right = 0; right < n; right++) {
            if (nums[right] > maxK || nums[right] < minK) {
                left = right + 1;
                ms.clear();
                continue;
            }

            ms.insert(nums[right]);

            while (left <= right && !ms.empty() && *ms.begin() == minK && *ms.rbegin() == maxK) {
                ans += dp[right];
                ms.erase(ms.find(nums[left]));
                left++;
            }
        }
        return ans;
        */
    }
};
// @lc code=end