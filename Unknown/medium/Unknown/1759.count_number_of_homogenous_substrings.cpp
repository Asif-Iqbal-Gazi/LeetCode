/*
 * @lc app=leetcode id=1759 lang=cpp
 *
 * [1759] Count Number of Homogenous Substrings
 */

// @lc code=start
class Solution {
   public:
    int countHomogenous(string s) {
        /* Approach:
            1. Sliding Window -- T.C: O(N), S.C: O(1)
            2. Sliding Window (Different Implementation) -- T.C: O(N), S.C: O(1)
        */

        // Approach 2
        int ans = 0;
        int n = s.size();
        int MOD = 1e9 + 7;

        int l = 0;
        for (int r = 0; r < n; r++) {
            if (s[r] != s[l]) l = r;
            ans = (ans + r - l + 1) % MOD;
        }
        return ans;

        /* Approach 1
        int ans = 0;
        int MOD = 1e9 + 7;
        int n = s.size();

        int l = 0, r = 0;
        long count = 0;
        for (r = 0; r <= n; r++) {
            if (r == n || s[r] != s[l]) {
                count = (1L * (r - l) * (r - l + 1)) / 2;
                ans = (ans % MOD + count % MOD) % MOD;
                l = r;
            }
        }

        return ans;
        */
    }
};
// @lc code=end
