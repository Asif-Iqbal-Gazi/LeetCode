/*
 * @lc app=leetcode id=1438 lang=cpp
 *
 * [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 */

// @lc code=start
class Solution {
   public:
    int longestSubarray(vector<int>& nums, int limit) {
        /* Approach:
            1. Bruteforce -- T.C: O(N^2), S.C: O(1)
            2. Sliding Window (MultiSet) -- T.C: O(N log N), S.C: O(N)
            3. Sliding Window (Monotonic Deque) -- T.C: O(N), S.C: O(N)
        */

        // Approach 3 -- Sliding Window (Monotonic Deque)
        int n = nums.size();
        int l = 0, r = 0, ans = 0;

        deque<int> maxq, minq;
        for (r = 0; r < n; r++) {
            while (!maxq.empty() && nums[maxq.back()] < nums[r])
                maxq.pop_back();
            while (!minq.empty() && nums[minq.back()] > nums[r])
                minq.pop_back();

            maxq.push_back(r);
            minq.push_back(r);

            while (nums[maxq.front()] - nums[minq.front()] > limit) {
                if (l == maxq.front())
                    maxq.pop_front();
                if (l == minq.front())
                    minq.pop_front();
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;

        /* Approach 2 -- Sliding Window (Multiset)
        int n = nums.size();
        int l = 0, r = 0, ans = 0;

        multiset<int> ms;
        for (r = 0; r < n; r++) {
            ms.insert(nums[r]);

            while (!ms.empty() && *ms.rbegin() - *ms.begin() > limit) {
                ms.erase(ms.find(nums[l++]));
            }
            ans = max(ans, r - l + 1);
        }

        return ans;
        */

        /* Approach 1 -- Bruteforce
        int n = nums.size();
        int ans = 0, maxi = 0, mini = 0;

        for (int i = 0; i < n; i++) {
            maxi = nums[i];
            mini = nums[i];
            for (int j = i; j < n; j++) {
                maxi = max(maxi, nums[j]);
                mini = min(mini, nums[j]);
                if (maxi - mini > limit) break;
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
        */
    }
};
// @lc code=end
