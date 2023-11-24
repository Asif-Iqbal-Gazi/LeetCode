/*
 * @lc app=leetcode id=1446 lang=cpp
 *
 * [1446] Consecutive Characters
 */

// @lc code=start
class Solution {
   public:
    int maxPower(string s) {
        /* Approach:
            1. Sliding Window -- T.C: O(N), S.C: O(1)
        */

        // Approach 1
        int n = s.size();

        int ans = 1;
        int l = 0, r = 0;
        for (r = 0; r < n; r++) {
            if (s[l] != s[r]) l = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
// @lc code=end
