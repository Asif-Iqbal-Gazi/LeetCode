/*
 * @lc app=leetcode id=1696 lang=cpp
 *
 * [1696] Jump Game VI
 */

// @lc code=start
class Solution {
   public:
    int maxResult(vector<int>& nums, int k) {
        /* Approach:
            1. DP (Bottom Up) -- T.C: O(N^2), S.C: O(N)
            2. DP (Optimised using Deque) -- T.C: O(N), S.C: O(N)
        */

        /*
            DP State:
                dp[i] : maximum score that can achieved jumping on ith index

            DP Transition:
                dp[i] = nums[i] + max(dp[j]), for all j: [i - k, i - 1]

            Base Case:
                dp[0] = nums[0];

            Final Answer:
                dp[n - 1]
        */

        // Approach 2 -- DP (Optimization using Deque)
        int r = 0, n = nums.size();
        deque<int> dq;
        dq.push_back(0);
        for (r = 1; r < n; r++) {
            if (r - dq.front() > k)
                dq.pop_front();

            nums[r] = nums[r] + nums[dq.front()];

            while (!dq.empty() && nums[dq.back()] <= nums[r])
                dq.pop_back();
            dq.push_back(r);
        }

        return nums[r - 1];

        /* Approach 1 -- DP (Bottom Up)
        int n = nums.size();
        int dp[n];
        // Base Case
        dp[0] = nums[0];

        for (int i = 1; i < n; i++) {
            int prevMax = INT_MIN;
            for (int j = max(0, i - k); j < i; j++) {
                prevMax = max(prevMax, dp[j]);
            }
            dp[i] = nums[i] + prevMax;
        }

        return dp[n - 1];
        */
    }
};
// @lc code=end
