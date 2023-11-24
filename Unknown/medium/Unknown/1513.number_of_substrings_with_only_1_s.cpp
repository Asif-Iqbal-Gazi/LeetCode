/*
 * @lc app=leetcode id=1513 lang=cpp
 *
 * [1513] Number of Substrings With Only 1s
 */

// @lc code=start
class Solution {
   public:
    int numSub(string s) {
        /* Approach:
            1. Sliding Window -- T.C: O(N), S.C: O(1)
        */

        // Approach 1
        int n = s.size();
        int MOD = 1e9 + 7;

        int ans = 0;
        int l = 0, r = 0;
        for (r = 0; r < n; r++) {
            if (s[r] ^ s[l]) l = r;
            if (s[l] == '1')
                ans = (ans + r - l + 1) % MOD;
        }
        return ans;
    }
};
// @lc code=end
