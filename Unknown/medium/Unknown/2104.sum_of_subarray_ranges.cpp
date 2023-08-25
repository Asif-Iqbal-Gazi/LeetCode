/*
 * @lc app=leetcode id=2104 lang=cpp
 *
 * [2104] Sum of Subarray Ranges
 */

// @lc code=start
class Solution {
   public:
    long long subArrayRanges(vector<int>& nums) {
        /* Approach:
            1. Bruteforce -- T.C: O(n^2), S.C: O(1)
            2. Stack Soluion -- T.C: O(n), S.C: O(n)
                -- We have find for all subarrays Σ [max - min] => for all subarrays Σ [max] - Σ [min]
                -- We will now find Σ [max] and Σ [min] individually, to do this:
                    at an index i, nums[i] is minimum for all subarrays that include nums[i], for this:
                    -- We will find the next smaller element on the left and right of nums[i] (NSL and NSR)
                    -- Now, we can find the number of subarrays that include nums[i] as minimum element
                    -- This is given by: (i - NSL) * (NSR - i)
                    -- Now, we can find the sum of all subarrays that include nums[i] as minimum element
                    -- This is given by: nums[i] * (i - NSL) * (NSR - i)
                -- Similarly, we can find Σ [max] for all subarrays using NGL and NGR
        */

        // Approach 2 -- Precalculate Max and Min array
        int n = nums.size();
        long long ans = 0;
        stack<int> st;

        // Get Σ [min] contribution
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                int j = st.top();  // nums[j] > nums[i], so for nums[j], index i is the smaller on right
                int right = i - j;
                st.pop();
                int left = st.empty() ? j + 1 : j - st.top();
                // Contribution of nums[j] as minimum in all subarrays
                ans -= (1LL * nums[j] * left * right);
            }
            st.push(i);
        }

        // At this point our stack has only one element (n)
        st.pop();

        // Get Σ [max] contribution
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] < nums[i])) {
                int j = st.top();  // nums[j] < nums[i], so for nums[j], index i is the greater on right
                int right = i - j;
                st.pop();
                int left = st.empty() ? j + 1 : j - st.top();
                // Contribution of nums[j] as maximum in all subarrays
                ans += (1LL * nums[j] * left * right);
            }
            st.push(i);
        }

        return ans;

        /* Approach 1 -- Bruteforce
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int maxi = INT_MIN;
            int mini = INT_MAX;
            for (int j = i; j < n; j++) {
                maxi = max(maxi, nums[j]);
                mini = min(mini, nums[j]);
                ans += (maxi - mini);
            }
        }

        return ans;
        */
    }
};
// @lc code=end
