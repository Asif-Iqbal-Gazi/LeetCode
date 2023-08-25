/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
   public:
    bool repeatedSubstringPattern(string s) {
        /* Approach:
            1. Divisor Method -- T.C: O(n * sqrt(n)), S.C: O(n)
        */

        // Approach 1 -- Divisor Method
        int n = s.size();

        for (int subStren = n / 2; subStren >= 1; subStren--) {
            if (n % subStren == 0) {
                if (s.substr(0, n - subStren) == s.substr(subStren)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
