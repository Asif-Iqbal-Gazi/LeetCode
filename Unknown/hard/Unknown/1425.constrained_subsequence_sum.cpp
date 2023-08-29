/*
 * @lc app=leetcode id=1425 lang=cpp
 *
 * [1425] Constrained Subsequence Sum
 */

// @lc code=start
class Solution {
   public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        /* Approach:
            1. DP (Bottom Up) -- T.C: O(N*k), S.C: O(N)
            2. DP (Optimised with Multiset) -- T.C: O(N * log k), S.C: O(k)
            3. DP (Optimised with Deque) -- T.C: O(N), S.C: O(k)
        */

        // Approach 3 -- DP (Optimised with Deque)
        int ans = nums[0];
        int n = nums.size();

        deque<int> dq;
        dq.push_back(0);

        for (int i = 1; i < n; i++) {
            nums[i] += max(0, nums[dq.front()]);

            if (i >= k) {
                // Reached the window length of k
                if (i - k == dq.front())
                    dq.pop_front();
            }
            // If we have found a new entry that is greater than what we have in our window,
            // i.e what we have in our deque, pop that out, as this new 'element' is greater
            // and it appears towards right
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);

            ans = max(ans, nums[i]);
        }
        return ans;

        /* Approach 2 -- DP (Optimised with Multiset)
        int ans = nums[0];
        int n = nums.size();

        multiset<long long> ms;
        ms.insert(nums[0]);

        for (int i = 1; i < n; i++) {
            nums[i] += max(1LL * 0, *ms.rbegin());
            // Reached the window length of k
            if (i >= k) ms.erase(ms.find(nums[i - k]));
            ms.insert(nums[i]);
            ans = max(ans, nums[i]);
        }
        return ans;
        */

        // Approach 1 -- DP
        // /*
        //     DP State:
        //         dp[i] : Maximum Sum of subsequence formed using prefixArray nums[0:i],
        //                 s.t, 'i'th element is part of the subsequence
        //     DP Transition:
        //         dp[i] = nums[i] + max({0, dp[i - 1], dp[i - 2], . . . , dp[i - k]});
        //     Base Case:
        //         dp[i] = nums[i];
        //     Final Answer:
        //         max dp[i], for all i
        // */
        // int ans = nums[0];
        // int n = nums.size();
        // cout << ans << " ";
        // for (int i = 1; i < n; i++) {
        //     int maxPrefix = 0;
        //     for (int j = max(0, i - k); j < i; j++) {
        //         maxPrefix = max(maxPrefix, nums[j]);
        //     }
        //     nums[i] += maxPrefix;
        //     ans = max(ans, nums[i]);
        // }

        // return ans;
    }
};
// @lc code=end
